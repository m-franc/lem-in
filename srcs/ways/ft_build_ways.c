/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/25 13:12:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_antsystem(t_adj_list *current_room)
{
	t_adj_list	*end;
	int			i;
	int			dist;

	i = 0;
	end = datas_graph->adj_list[datas_graph->nb_rooms - 1];
	dist = 0;
	while (i < end->nb_tunnels)
	{
		end->rooms_linked[i]->dist = dist;
		ft_init_room_way(end->rooms_linked[i], dist++);
		i++;
	}
}

int			ft_build_ways(t_datas_graph *datas_graph)
{
	ft_antsystem(datas_graph->adj_list[datas_graph->nb_rooms - 1]);

/*	ft_init_start_ways(datas_graph);
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
	}*/
//	ft_put_ways(datas_graph->ways);
	return (1);
}
