/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:10:01 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/05 14:42:17 by mfranc           ###   ########.fr       */
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
		if (rooms[i].rooms_linked)
			ft_memdel((void**)rooms[i].rooms_linked);
		ft_bzero(&rooms[i], sizeof(t_adj_list));
		i++;	
	}
	ft_memdel((void**)&rooms);
}

void					ft_del_datas_graph(t_datas_graph *datas_graph)
{
	if (datas_graph->adj_list)
		ft_del_adj_list(datas_graph);
}

void					ft_del_data_store(t_data_store *data_store)
{
	(void)data_store;
}

void					ft_exit_error(t_data_store *data_store, t_datas_graph *datas_graph)
{
	if (datas_graph)
		ft_del_datas_graph(datas_graph);
	if (data_store)
		ft_del_data_store(data_store);
	ft_printf("%w{red}ERROR{eoc}\n", 2);
	exit(1);
}

int						ft_exit_function(int return_value, void *st_elem,
		void *nd_elem, void *rd_elem)
{
	ft_memdel(&st_elem);
	ft_memdel(&nd_elem);
	ft_memdel(&rd_elem);
	return (return_value);
}
