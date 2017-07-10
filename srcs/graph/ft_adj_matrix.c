/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adj_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:50:44 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/10 17:45:45 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_switchon_tunnels_adj_matrix(t_datas_graph *datas_graph)
{
	int		**matrix;
	t_adj_list	**list;
	t_adj_list	**rooms_linked;
	int		i;
	int		o;

	matrix = datas_graph->adj_matrix;
	list = datas_graph->adj_list;
	i = 0;
	while (i < datas_graph->nb_rooms)
	{
		rooms_linked = list[i]->rooms_linked;
		o = 0;
		while (o < list[i]->nb_tunnels)
		{
			matrix[i][rooms_linked[o]->id] = 1;
			o++;
		}
		i++;
	}
}
