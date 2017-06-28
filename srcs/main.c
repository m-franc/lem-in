/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:11:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/28 12:22:18 by mfranc           ###   ########.fr       */
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
	data_store->rooms = ft_data_rooms_init();
	data_store->tunnels = NULL;
	return (data_store);
}

int 					main(int ac, char **av)
{
	t_data_store		*data_store;

	(void)ac;
	(void)av;
	data_store = ft_data_store_init();
	return (0);
}
