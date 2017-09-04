/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_sitting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 12:55:16 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/04 18:28:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_update_rooms_id(t_datas_graph *datas_graph)
{
	t_adj_list	*list;
	int			i;

	i = 0;
	list = datas_graph->adj_list;
	while (i < datas_graph->nb_rooms)
	{
		list[i].id = i;
		i++;
	}
}
