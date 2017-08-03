/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/03 17:12:54 by mfranc           ###   ########.fr       */
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

void			ft_map_crosser(int nb_ants, t_datas_graph *datas_graph)
{
	int			ant_number;
	int			nb_ants_cpy;
	t_adj_list	**rooms;
	t_adj_list	*curr_room;
	int			room_index;

	ant_number = 1;
	nb_ants_cpy = nb_ants;
	while (42)
	{
		if (nb_ants == nb_ants_cpy)	
			curr_room = rooms[0];
		else
			curr_room = ft_get_next_room(datas_graph->adj_list, curr_room)
		if (nb_ants == ant_number && curr_room->end)
			break ;
		if (ant_number <= nb_ants)
			ant_number++;
	}
}
