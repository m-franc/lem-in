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
	data_store->nb_rooms = 0;
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
	ft_build_adj_list(data_store, datas_graph->adj_list);
	ft_init_rooms_linked(data_store, datas_graph);
	int o = 0;
	int i = 0;
	t_adj_list **list = datas_graph->adj_list;
	t_data_rooms *rooms = data_store->rooms;
	while (list[o])
	{
		ft_printf("{grey}%s{eoc}", list[o]->name);
		if (!list[o]->rooms_linked)
			ft_putchar('\n');
		else
		{
			ft_putstr(" -> ");
			i = 0;
			t_adj_list **tmp_list = list[o]->rooms_linked;
			while (tmp_list[i])
			{
				ft_printf("%s", tmp_list[i]->name);
				ft_putstr(", ");
				i++;
			}
			ft_putchar('\n');
		}
		o++;
		rooms = rooms->next;
	}
	return (0);
}
