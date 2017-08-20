/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_start_ways.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:54:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/20 14:18:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
/*
t_adj_list		*ft_new_room_way(t_adj_list *content_elem_list)
{
	t_adj_list	*new_room;

	new_room = ft_memalloc(sizeof(t_adj_list));
	new_room = ft_memcpy(new_room, content_elem_list, sizeof(t_adj_list));
	new_room->linked = 1;
	return (new_room);
}

void			ft_push_back_ways(t_ways **ways, t_ways *new_way)
{
	t_ways		*tmp_ways;
	t_ways		*prev;

	if (!*ways)
	{
		*ways = new_way;
		(*ways)->prev = NULL;
	}
	else
	{
		tmp_ways = *ways;
		prev = tmp_ways;
		while (tmp_ways && tmp_ways->next)
		{
			tmp_ways = tmp_ways->next;
			prev = tmp_ways;	
		}
		tmp_ways->next = new_way;
		new_way->prev = prev;
	}
}

t_ways			*ft_new_way(t_adj_list *content_elem_list, int id)
{
	t_ways		*new_way;

	new_way = ft_memalloc(sizeof(t_ways));
	new_way->id = id; 
	new_way->ended = 0;
	new_way->nb_rooms = 1;
	new_way->rooms = ft_new_room_way(content_elem_list);
	new_way->next = NULL;
	new_way->prev = NULL;
	return (new_way);
}

void			ft_init_start_ways(t_datas_graph *datas_graph)
{
	t_ways		*new_way;
	t_ways		*ways;
	t_adj_list	*start_room;
	int			i;

	start_room = datas_graph->adj_list[0];
	ways = datas_graph->ways;
	i = -1;
	while (++i < datas_graph->adj_list[0]->nb_tunnels)
	{	
		ways = datas_graph->ways;
		new_way = ft_new_way(start_room, i);
		if (!datas_graph->ways)
			ft_push_back_ways(&datas_graph->ways, new_way);
		else
			ft_push_back_ways(&ways, new_way);
	}
}*/
