/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:11:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 19:31:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_data_store			*ft_data_store_init(void)
{
	t_data_store 		*data_store;

	if (!(data_store = (t_data_store*)malloc(sizeof(t_data_store))))
		exit(-1);
	data_store->nb_ants = 0;
	data_store->start_mark = 0;
	data_store->end_mark = 0;
	data_store->rooms = NULL;
	data_store->nb_rooms = 1;
	data_store->tunnels = NULL;
	data_store->nb_tunnels = 0;
	data_store->commands = NULL;
	return (data_store);
}

void					ft_exit_error(void)
{
	ft_putstrcolor("ERROR\n", RED);
	exit(-1);
}

t_datas_graph				*ft_init_datas_graph(t_data_store *data_store)
{
	t_datas_graph	*datas_graph;
	int		**adj_matrix;
	t_adj_list	*adj_list;
	int		i;

	if (!(datas_graph = (t_datas_graph*)malloc(sizeof(t_datas_graph))))
		exit(1);
	i = -1;
	adj_matrix = ft_memalloc(sizeof(int*) * data_store->nb_rooms);
	while (++i < data_store->nb_rooms)
		adj_matrix[i] = ft_memalloc(sizeof(int) * data_store->nb_rooms);
	datas_graph->adj_matrix = adj_matrix;
	adj_list = ft_memalloc(sizeof(t_adj_list) * data_store->nb_rooms);
	datas_graph->adj_list = adj_list;
	return (datas_graph);
}

int 					main(void)
{
	t_data_store		*data_store;
	int					parsing_ret;
	t_datas_graph		*datas_graph;
	
	data_store = ft_data_store_init();
	if ((parsing_ret = ft_parse_file(data_store)) == -1)
		ft_exit_error();
	if ((ft_check_room_tunnel(data_store)) == -1)
		ft_exit_error();
	ft_put_data_parsed(data_store);
	datas_graph = ft_init_datas_graph(data_store);
	return (0);
}
