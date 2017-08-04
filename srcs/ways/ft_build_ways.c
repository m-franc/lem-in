/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/04 14:56:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

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
			if (!next_rooms[i]->dist || next_rooms[i]->dist > (dist + 1))
				ft_init_dist(next_rooms[i], dist + 1);
	}
}

t_adj_list		*ft_get_next_room(t_adj_list **og_rooms, t_adj_list *curr_room)
{
	int			nb_tunnels;
	int			shortter_to_end_room;

	nb_tunnels = curr_room->nb_tunnels;
	shortter_to_end_room = 2147483647;
	while (nb_tunnels-- > 0)
	{
		if ((shortter_to_end_room > curr_room[nb_tunnels]->dist) && (curr_room[nb_tunnels]->dist > 0))
			shortter_to_end_room = curr_room[nb_tunnels]->id;
	}
	return (og_rooms[shortter_to_end_room]);
}

/*int				ft_ant_in_map(t_datas_graph *datas_graph)
{
	int			i;

	i = 0;
	while (i < datas_graph->nb_rooms && datas_graph->adj_list[i]->ant_in)
		i++;
	if (i != datas_graph->nb_rooms)
		return (0);
	else
		return (1);
}*/

void			ft_launch_ants_map(int ant_number, int nb_ants, t_adj_list *first_room)
{
	
}

void			ft_map_crosser(int nb_ants, t_datas_graph *datas_graph)
{
	int			ant_number;
	t_adj_list	**rooms;
	t_adj_list	*curr_room;
	int			room_index;

	ant_number = 1;
	rooms = datas_graph->adj_list;
	curr_room = rooms[0];
	while (datas_graph->adj_list[datas_graph->nb_rooms - 1]->ant_in != nb_ants)
	{
		ft_launch_ants_map(ant_number, nb_ants, rooms);
		curr_room = ft_get_next_room(datas_graph->adj_list, curr_room)
		if (ant_number <= nb_ants)
			ant_number++;
	}
}
