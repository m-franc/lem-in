/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:39:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/07 19:46:26 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_sort_link_room(t_adj_list *room)
{
	t_adj_list	**links;
	t_adj_list	*tmp_link;
	int			j;

	j = 0;
	links = room->rooms_linked;
	while (j < room->nb_tunnels - 1)
	{
		while (links[j]->dist > links[j + 1]->dist || links[j + 1]->end)
		{
			tmp_link = links[j];
			links[j] = links[j + 1];
			links[j + 1] = tmp_link;
			j = 0;
		}
		j++;
	}
}

int				ft_get_index_next_room(t_adj_list *curr_room)
{
	int			i;
	int			index_next_room;
	int			dist_min;

	i = -1;
	dist_min = 2147483647;
	index_next_room = -1;
	while (++i < curr_room->nb_tunnels)
	{
		if (curr_room->rooms_linked[i]->end)
			return (i);
		else if (curr_room->rooms_linked[i]->dist < dist_min
				&& curr_room->rooms_linked[i]->dist > 0
				&& curr_room->rooms_linked[i]->way_id == 0
				&& curr_room->rooms_linked[i]->way_start == 0)
		{
			dist_min = curr_room->rooms_linked[i]->dist;
			index_next_room = i;
		}
	}
	return (index_next_room);
}

int				ft_init_way(t_adj_list *start_room_link, int way_id)
{
	t_adj_list	*curr_room;
	int			index_next_room;

	start_room_link->way_id = way_id;
	curr_room = start_room_link;
	while (!curr_room->end)
	{
		if ((index_next_room = ft_get_index_next_room(curr_room)) == -1)
			return (-1);
		if (!curr_room->rooms_linked[index_next_room]->end)
			curr_room->rooms_linked[index_next_room]->way_id = way_id;
		curr_room = curr_room->rooms_linked[index_next_room];
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
	start_room = &datas_graph->adj_list[0];
	ft_sort_link_room(start_room);
	start_room->way_id = -1;
	datas_graph->adj_list[datas_graph->nb_rooms - 1].way_id = -1;
	datas_graph->nb_ways = start_room->nb_tunnels;
	next_rooms = start_room->rooms_linked;
	while (++i < start_room->nb_tunnels)
	{
		start_room->rooms_linked[i]->way_start = 1;
		if ((ft_init_way(start_room->rooms_linked[i], way_id)) == -1)
		{
			datas_graph->nb_ways--;
			start_room->rooms_linked[i]->way_id = 0;
		}
		else
			way_id++;
	}
}
