/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:18:09 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/04 18:25:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_init_dist(t_adj_list *current_room, int dist)
{
	t_adj_list	**next_rooms;
	int			i;

	current_room->dist = dist;
	if (current_room->start == 1)
		return ;
	i = -1;
	next_rooms = current_room->rooms_linked;
	while (++i < current_room->nb_tunnels)
	{
		if (!next_rooms[i]->end)
		{
			if (!next_rooms[i]->dist || next_rooms[i]->dist > (dist + 1))
				ft_init_dist(next_rooms[i], dist + 1);
		}
	}
}

void			ft_move_ant_room(t_adj_list *curr_room,
		t_adj_list *next_room, t_ants *ant)
{
	next_room->ant_in += ant->ant_number;
	ant->curr_room->ant_in = 0;
	ant->curr_room = next_room;
	ant->prev_room = curr_room;
	ft_printf("L%d-%s", ant->ant_number, ant->curr_room->name);
}

t_adj_list		*ft_get_next_room_way(t_adj_list *curr_room,
		t_adj_list *prev_room, int way_id)
{
	int			nb_tunnels;
	int			i_shortter_room_to_end;
	int			i;
	t_adj_list	**next_rooms;

	nb_tunnels = curr_room->nb_tunnels;
	next_rooms = curr_room->rooms_linked;
	i = 0;
	i_shortter_room_to_end = 0;
	while (i < nb_tunnels)
	{
		if (next_rooms[i]->end)
			i_shortter_room_to_end = i;
		else if (next_rooms[i]->way_id == way_id
				&& !ft_strequ(prev_room->name, next_rooms[i]->name))
			i_shortter_room_to_end = i;
		i++;
	}
	return (next_rooms[i_shortter_room_to_end]);
}

void			ft_move_ants_map(t_datas_graph *datas_graph)
{
	t_adj_list	*next_room;
	t_ants		*ants;
	int			i;

	ants = datas_graph->ants;
	i = 0;
	while (ants)
	{
		next_room = ft_get_next_room_way(ants->curr_room,
				ants->prev_room, ants->way_id);
		if (!next_room->ant_in || next_room->end)
		{
			if (i++ != 0)
				ft_putchar(' ');
			ft_move_ant_room(ants->curr_room, next_room, ants);
		}
		ants = ants->next;
	}
}

void			ft_map_crosser(t_datas_graph *datas_graph)
{
	t_adj_list	*rooms;
	t_adj_list	end_room;

	rooms = datas_graph->adj_list;
	end_room = datas_graph->adj_list[datas_graph->nb_rooms - 1];
	while (datas_graph->ants)
	{
		ft_move_ants_map(datas_graph);
		ft_del_ants_comed(datas_graph);
		ft_putchar('\n');
	}
}
