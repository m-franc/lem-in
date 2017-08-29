/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_next_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/29 16:46:02 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_update_rooms_id(t_datas_graph *datas_graph)
{
	t_adj_list	*list;
	int		i;

	i = 0;
	list = datas_graph->adj_list;
	while (i < datas_graph->nb_rooms)
	{
		list[i].id = i;
		i++;
	}
}
