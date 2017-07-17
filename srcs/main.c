/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:11:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/17 18:44:49 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_data_store			*ft_data_store_init(void)
{
	t_data_store 		*data_store;

	data_store = ft_memalloc(sizeof(t_data_store));
	data_store->nb_ants = 0;
	data_store->start_mark = 0;
	data_store->end_mark = 0;
	data_store->rooms = NULL;
	data_store->nb_rooms = 0;
	data_store->tunnels = NULL;
	data_store->nb_tunnels = 0;
	data_store->commands = NULL;
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
	
	data_store = ft_data_store_init();
	if ((parsing_ret = ft_parse_file(data_store)) == -1)
		ft_exit_error();
//	if ((ft_check_room_tunnel(data_store)) == -1)
//		ft_exit_error();
	if (!(datas_graph = ft_init_datas_graph(data_store)))
		ft_exit_error();
//	ft_put_data_parsed(data_store);
	if ((ft_build_graph(data_store, datas_graph)) == -1)
		ft_exit_error();
	ft_put_adj_list(datas_graph);
//	ft_put_adj_matrix(datas_graph);
	if (!ft_build_ways(datas_graph))
		ft_exit_error();
	return (0);
}
