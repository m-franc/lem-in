/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/18 21:46:13 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_build_ways(t_datas_graph *datas_graph)
{
	t_ways		*ways;
	t_adj_list	*last_room;

	ft_init_start_ways(datas_graph);
	ft_init_second_room(datas_graph);	
	ways = datas_graph->ways;
	while (ways)
	{
		last_room = ft_get_current_last_room_way(ways);
		if (last_room->nb_tunnels == 0 || last_room->end)
			ways = ways->next;
		else
		{
			if (ft_init_next_rooms(datas_graph, last_room, ways) == 0)
				ways = ways->next;	
		}
	//	sleep(1);
	}
//	PSTR("------------------------")
//	ft_put_ways(datas_graph->ways);
	return (1);
}
