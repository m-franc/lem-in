/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:51:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/04 18:25:39 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_datas_graph		*ft_init_datas_graph(t_data_store *data_store)
{
	t_datas_graph	*datas_graph;
	t_adj_list		*adj_list;

	if (data_store->nb_rooms == 0)
		return (NULL);
	if (!(datas_graph = ft_memalloc(sizeof(t_datas_graph))))
		return (NULL);
	if (!(adj_list = ft_memalloc(sizeof(t_adj_list) * (data_store->nb_rooms))))
	{
		ft_memdel((void**)&datas_graph);
		return (NULL);
	}
	datas_graph->adj_list = adj_list;
	datas_graph->nb_links = 0;
	datas_graph->nb_rooms = data_store->nb_rooms;
	datas_graph->nb_ways = 0;
	datas_graph->nb_ants = data_store->nb_ants;
	datas_graph->ants = NULL;
	return (datas_graph);
}

int					ft_build_graph(t_data_store *data_store,
		t_datas_graph *datas_graph)
{
	if ((ft_build_adj_list(data_store, datas_graph)) == -1)
		return (-1);
	if ((ft_sort_graph(datas_graph)) == -1)
		return (-1);
	if ((ft_build_tunnels_adj_list(data_store->tunnels, datas_graph)) == -1)
		return (-1);
	return (1);
}
