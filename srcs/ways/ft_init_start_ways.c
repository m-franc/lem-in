/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_start_ways.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:54:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/13 20:54:53 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_push_back_ways(t_ways **ways, t_ways *new_way)
{
	t_ways		*tmp_ways;

	if (!*ways)
		*ways = new_way;
	else
	{
		tmp_ways = *ways;
		while (tmp_ways && tmp_ways->next)
			tmp_ways = tmp_ways->next;
		tmp_ways->next = new_way;
	}
}

void			ft_new_way(t_adj_list *content_elem_list, t_datas_graph *datas_graph, int id)
{
	t_ways		*new_way;
	t_ways		*ways;
	t_adj_list	*content_elem_way;

	ways = datas_graph->ways;
	new_way = ft_memalloc(sizeof(t_ways));
	content_elem_way = ft_memalloc(sizeof(t_adj_list));
	new_way->id = id; 
	new_way->rooms = ft_memcpy(content_elem_way, content_elem_list, sizeof(t_adj_list));
	new_way->next = NULL;
	if (!datas_graph->ways)
		ft_push_back_ways(&datas_graph->ways, new_way);
	else
		ft_push_back_ways(&ways, new_way);
}

void			ft_init_start_ways(t_datas_graph *datas_graph)
{
	t_adj_list	*start_room;
	int			i;

	start_room = datas_graph->adj_list[0];
	i = -1;
	while (++i < datas_graph->adj_list[0]->nb_tunnels)
		ft_new_way(start_room, datas_graph, i);
}


