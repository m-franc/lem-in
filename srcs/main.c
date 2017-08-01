/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:11:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/26 19:47:50 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_data_store			*ft_data_store_init(void)
{
	t_data_store 		*data_store;

	if (!(data_store = ft_memalloc(sizeof(t_data_store))))
		return (NULL);
	data_store->nb_ants = 0;
	data_store->start_mark = 0;
	data_store->end_mark = 0;
	data_store->rooms = NULL;
	data_store->nb_rooms = 0;
	data_store->tunnels = NULL;
	data_store->nb_tunnels = 0;
	data_store->commands = NULL;
	data_store->nb_commands = 0;
	return (data_store);
}

void					ft_exit_error(void)
{
	ft_putstrcolor("ERROR\n", RED);
	exit(1);
}

int 					main(void)
{
	t_data_store		*data_store;
	int					parsing_ret;
	t_datas_graph		*datas_graph;
	
	if (!(data_store = ft_data_store_init()))
		ft_exit_error();
	if ((parsing_ret = ft_parse_file(data_store)) == -1)
		ft_exit_error();
	ft_put_data_parsed(data_store);
	if (!(datas_graph = ft_init_datas_graph(data_store)))
		ft_exit_error();
	if ((ft_build_graph(data_store, datas_graph)) == -1)
		ft_exit_error();
	ft_init_dist(datas_graph->adj_list[datas_graph->nb_rooms - 1], 0);
//	ft_put_adj_list_dist(datas_graph);
//	ft_put_adj_matrix(datas_graph);
	return (0);
}
