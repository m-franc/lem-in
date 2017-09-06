/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_datas_graph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:44:52 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/06 10:53:24 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_del_adj_list(t_datas_graph *datas_graph)
{
	t_adj_list			*rooms;
	int					i;

	i = 0;
	rooms = datas_graph->adj_list;
	while (i < datas_graph->nb_rooms)
	{
		free(rooms[i].rooms_linked);
		ft_bzero(&rooms[i], sizeof(t_adj_list));
		i++;
	}
	ft_memdel((void**)&rooms);
}

void					ft_del_ants(t_ants *ants)
{
	t_ants				*curr_ant;
	t_ants				*to_free;

	while (ants)
	{
		curr_ant = ants->next;
		to_free = ants;
		ft_bzero(to_free, sizeof(t_ants));
		ft_memdel((void**)&to_free);
		to_free = NULL;
		ants = curr_ant;
	}
}

void					ft_del_datas_graph(t_datas_graph *datas_graph)
{
	if (datas_graph->ants)
		ft_del_ants(datas_graph->ants);
	if (datas_graph->adj_list)
		ft_del_adj_list(datas_graph);
	ft_bzero(datas_graph, sizeof(t_datas_graph));
	ft_memdel((void**)&datas_graph);
}
