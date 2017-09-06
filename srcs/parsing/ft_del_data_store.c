/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_data_store.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:21:18 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/06 10:54:16 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_del_rooms(t_data_rooms *rooms)
{
	t_data_rooms		*curr_room;
	t_data_rooms		*to_free;

	while (rooms)
	{
		curr_room = rooms->next;
		to_free = rooms;
		ft_bzero(to_free, sizeof(t_data_rooms));
		ft_memdel((void**)&to_free);
		to_free = NULL;
		rooms = curr_room;
	}
}

void					ft_del_tunnels(t_tunnels *tunnels)
{
	t_tunnels			*curr_tunnel;
	t_tunnels			*to_free;

	while (tunnels)
	{
		curr_tunnel = tunnels->next;
		to_free = tunnels;
		ft_bzero(to_free, sizeof(t_tunnels));
		ft_memdel((void**)&to_free);
		to_free = NULL;
		tunnels = curr_tunnel;
	}
}

void					ft_del_data_store(t_data_store *data_store)
{
	if (data_store->rooms)
		ft_del_rooms(data_store->rooms);
	if (data_store->tunnels)
		ft_del_tunnels(data_store->tunnels);
	if (data_store->commands)
		ft_lstdel(&data_store->commands);
	ft_bzero(data_store, sizeof(t_data_store));
	ft_memdel((void**)&data_store);
}
