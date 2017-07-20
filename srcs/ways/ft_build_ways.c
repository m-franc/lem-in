/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/20 20:16:46 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_init_room_dst()

void			ft_antsystem(t_datas_graph *datas_graph)
{
	t_adj_list	**rooms_linked;
	t_adj_list	*end;
	int			i;
	int			j;

	i = 0;
	end = datas_graph->adj_list[datas_graph->nb_rooms - 1];
	while (i < end->nb_tunnels)
	{
		
		i++;
	}
}

int			ft_build_ways(t_datas_graph *datas_graph)
{
	ft_antsystem(datas_graph);

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
