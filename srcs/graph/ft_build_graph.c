/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:51:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/26 19:41:56 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_datas_graph		*ft_init_datas_graph(t_data_store *data_store)
{
	t_datas_graph	*datas_graph;
	int				**adj_matrix;
	int				*elem_adj_matrix;
	t_adj_list		**adj_list;
	int				i;

	if (data_store->nb_rooms == 0)
		return (NULL);
	datas_graph = ft_memalloc(sizeof(t_datas_graph));
	i = -1;
	adj_matrix = ft_memalloc(sizeof(int*) * (data_store->nb_rooms));
	while (++i < data_store->nb_rooms)
	{
		elem_adj_matrix = ft_memalloc(sizeof(int) * data_store->nb_rooms);
		adj_matrix[i] = elem_adj_matrix;
	}
	datas_graph->adj_matrix = adj_matrix;
	adj_list = ft_memalloc(sizeof(t_adj_list*) * (data_store->nb_rooms));
	datas_graph->adj_list = adj_list;
	datas_graph->nb_links = 0;
	datas_graph->nb_rooms = data_store->nb_rooms;
	datas_graph->ways = NULL;
	return (datas_graph);
}

void			ft_switchon_tunnels_adj_matrix(t_datas_graph *datas_graph)
{
	int			**matrix;
	t_adj_list	**list;
	t_adj_list	**rooms_linked;
	int			i;
	int			o;

	matrix = datas_graph->adj_matrix;
	list = datas_graph->adj_list;
	i = -1;
	while (++i < datas_graph->nb_rooms)
	{
		if (list[i]->rooms_linked) 
		{
			rooms_linked = list[i]->rooms_linked;
			o = -1;
			while (++o < list[i]->nb_tunnels)
			{
				matrix[i][rooms_linked[o]->id] = 1;
				datas_graph->nb_links++;
			}
		}
	}
}

int			ft_build_graph(t_data_store *data_store, t_datas_graph *datas_graph)
{
	if ((ft_build_adj_list(data_store, datas_graph)) == -1)
		return (-1);
	if ((ft_sort_graph(datas_graph)) == -1)
		return (-1);
	if ((ft_build_tunnels_adj_list(data_store->tunnels, datas_graph)) == -1)
		return (-1);
	ft_switchon_tunnels_adj_matrix(datas_graph);
	return (1);
}
