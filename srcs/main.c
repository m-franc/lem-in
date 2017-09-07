/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:11:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/07 21:24:38 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_graph_building_and_setting(t_data_store *data_store,
		t_datas_graph **datas_graph)
{
	t_adj_list			*tmp_rooms;

	if (!(*datas_graph = ft_init_datas_graph(data_store)))
		ft_exit_error(data_store, *datas_graph);
	if ((ft_build_graph(data_store, *datas_graph)) == -1)
		ft_exit_error(data_store, *datas_graph);
	tmp_rooms = (*datas_graph)->adj_list;
	ft_init_dist(&tmp_rooms[(*datas_graph)->nb_rooms - 1], 0);
	if ((*datas_graph)->adj_list[0].dist == 0)
		ft_exit_error(data_store, *datas_graph);
}

void					ft_parse_and_store(t_data_store **data_store)
{
	int					parsing_ret;

	if (!(*data_store = ft_data_store_init()))
		ft_exit_error(*data_store, NULL);
	if ((parsing_ret = ft_parse_file(*data_store)) == -1)
		ft_exit_error(*data_store, NULL);
	ft_check_tunnels(*data_store);
}

void					ft_anthill_part(t_list *commands,
		t_datas_graph *datas_graph)
{
	ft_init_ways(datas_graph);
	ft_init_ants(datas_graph);
	ft_init_ways_ants(datas_graph, datas_graph->adj_list[0].rooms_linked);
	ft_putlist(commands);
	ft_putchar('\n');
	ft_map_crosser(datas_graph);
}

void					lem_in(void)
{
	t_data_store		*data_store;
	t_datas_graph		*datas_graph;

	data_store = NULL;
	datas_graph = NULL;
	ft_parse_and_store(&data_store);
	ft_graph_building_and_setting(data_store, &datas_graph);
	ft_anthill_part(data_store->commands, datas_graph);
	ft_del_datas_graph(datas_graph);
	ft_del_data_store(data_store);
}

int						main(void)
{
	lem_in();
	return (0);
}
