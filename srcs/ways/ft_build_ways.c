/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/18 12:43:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_build_ways(t_datas_graph *datas_graph)
{
	t_ways		*ways;
	t_adj_list	*rooms;
	int		ended;

	ft_init_start_ways(datas_graph);
	ft_init_second_room(datas_graph);	
	ways = datas_graph->ways;
	ended = 0;
	while (ways && !ways->rooms->end)
	{
		rooms = ways->rooms;
		while (rooms && !rooms->end)
		{
			ft_init_next_rooms(datas_graph, &ways);
			if (rooms->end)
				ended++;
			rooms = rooms->next;
			sleep(1);
			ft_put_ways(datas_graph->ways);
		}
		ways = ways->next;
	}
	return (1);
}
