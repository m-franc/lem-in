/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:39:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/21 12:49:16 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_sort_link_room(t_adj_list *room)
{
	t_adj_list	**links;
	t_adj_list	*tmp_link;
	int			j;

	j = 0;
	links = room->rooms_linked;
	while (j < room->nb_tunnels - 1)
	{
		while (links[j]->dist > links[j + 1]->dist)
		{
			tmp_link = links[j];
			links[j] = links[j + 1];
			links[j + 1] = tmp_link;
			j = 0;
		}
		j++;
	}
}

int				ft_init_way(t_adj_list *start_room_link, int way_id)
{
	t_adj_list	*curr_room;
	int			i;

	curr_room = start_room_link;
	while (!curr_room->end)
	{
		ft_sort_link_room(curr_room);
		i = -1;
		while (++i < curr_room->nb_tunnels && curr_room->rooms_linked[i]->way_id)
			;
		if (i == curr_room->nb_tunnels)
			return (-1);
		curr_room->rooms_linked[i]->way_id = way_id;
		curr_room = curr_room->rooms_linked[i];
	}
	return (1);
}

void			ft_init_ways(t_datas_graph *datas_graph)
{
	int			way_id;
	int			i;
	t_adj_list	**next_rooms;
	t_adj_list	*start_room;

	way_id = 1;
	i = -1;
	start_room = datas_graph->adj_list[0];
	ft_sort_link_room(start_room);
	next_rooms = start_room->rooms_linked;
	while (++i < start_room->nb_tunnels)
	{
		if ((ft_init_way(start_room->rooms_linked[i], way_id)) == -1)
			start_room->rooms_linked[i]->way_id = 0;
		way_id++;
	}
}
