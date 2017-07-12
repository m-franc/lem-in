/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/12 16:32:37 by mfranc           ###   ########.fr       */
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
		while (tmp_ways)
			tmp_ways = tmp_ways->next;
		tmp_ways->next = new_way;
	}
}

void			ft_store_elem_way(t_adj_list *content_elem_way, t_ways *ways)
{
	t_ways		*new_way;

	new_way = ft_memalloc(sizeof(t_ways));
	new_way->way = content_elem_way;
	new_way->next = NULL;
	ft_push_back_ways(&ways, new_way);
}

void			ft_init_start_ways(t_datas_graph *datas_graph)
{
	t_adj_list	*start_room;
	int			i;

	start_room = datas_graph->adj_list[0];
	i = -1;
	while (++i < datas_graph->adj_list[0]->nb_tunnels)
		ft_store_elem_way(start_room, datas_graph->ways);
}

void			ft_build_ways(t_datas_graph *datas_graph)
{
	ft_init_start_ways(datas_graph);
}
