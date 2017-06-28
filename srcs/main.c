/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:11:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/28 16:48:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_ctl_data_rooms		*ft_data_rooms_init(void)
{
	t_ctl_data_rooms	*rooms;

	if (!(rooms = (t_ctl_data_rooms*)malloc(sizeof(t_ctl_data_rooms))))
		exit(-1);
	rooms->size = 0;
	rooms->first = NULL;
	rooms->last = NULL;
	return (rooms);
}

t_data_store			*ft_data_store_init(void)
{
	t_data_store 		*data_store;

	if (!(data_store = (t_data_store*)malloc(sizeof(t_data_store))))
		exit(-1);
	data_store->nb_ants = 0;
	data_store->start_mark = 0;
	data_store->end_mark = 0;
	data_store->rooms = ft_data_rooms_init();
	data_store->tunnels = NULL;
	return (data_store);
}

void					ft_exit_error()
{
	ft_putstrcolor("ERROR\n", RED);
	exit(-1);
}

int 					main(void)
{
	t_data_store		*data_store;
	int					parsing_ret;
	
	data_store = ft_data_store_init();
	if ((parsing_ret = t_parse_file(data_store)) == -1)
		ft_exit_error();
	else if ((parsing_ret = t_parse_file(data_store)) == 0)
		ft_putendl("ok");
	return (0);
}
