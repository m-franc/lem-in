/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   updated: 2017/07/13 20:54:26 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_ways_ended(t_ways *ways)
{
	t_ways		*tmp_ways;
	t_adj_list	*tmp_rooms;
	int		ended;

	tmp_ways = ways;
	ended = 0;
	while (tmp_ways)
	{
		tmp_rooms = tmp_ways->rooms;
		while (tmp_rooms && tmp_rooms->next)
			tmp_rooms = tmp_rooms->next;
		if (tmp_rooms->end == 1)
			return (1);
		tmp_ways = tmp_ways->next;
	}
	return (0);
}

int			ft_build_ways(t_datas_graph *datas_graph)
{
	t_ways		*ways;
	t_adj_list	*rooms;
	int		ended;

	ft_init_start_ways(datas_graph);
	ft_init_second_room(datas_graph);	
	ways = datas_graph->ways;
	ended = 0;
	while (ways)
	{
		rooms = ways->rooms;
		while (rooms)
		{
			ft_init_next_rooms(datas_graph, ways);
			if (rooms->end)
				ended++;
			rooms = rooms->next;
		}
		ways = ways->next;
	}
	return (ended);
}
