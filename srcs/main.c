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
	
	data_store = ft_data_store_init();
	parsing_ret = ft_parse_file(data_store);
	if (parsing_ret == -1)
		ft_exit_error();
	else if (parsing_ret == 0)
		ft_putendl("ok");
	return (0);
}
