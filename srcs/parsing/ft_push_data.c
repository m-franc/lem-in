/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/04 12:39:33 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void				ft_push_back_tunnel(t_data_store *data_store,
		t_tunnels *new_tunnel)
{
	if (data_store->tunnels)
	{
		data_store->last_tunnels->next = new_tunnel;
		data_store->last_tunnels = data_store->last_tunnels->next;
	}
	else
	{
		data_store->tunnels = new_tunnel;
		data_store->last_tunnels = new_tunnel;
	}
}

void				ft_push_back_room(t_data_store *data_store,
		t_data_rooms *new_room)
{
	if (data_store->rooms)
	{
		data_store->last_rooms->next = new_room;
		data_store->last_rooms = data_store->last_rooms->next;
	}
	else
	{
		data_store->rooms = new_room;
		data_store->last_rooms = new_room;
	}
}

void				ft_push_back_command(t_data_store *data_store,
		t_list *new_command)
{
	if (data_store->commands)
	{
		data_store->last_commands->next = new_command;
		data_store->last_commands = data_store->last_commands->next;
	}
	else
	{
		data_store->commands = new_command;
		data_store->last_commands = new_command;
	}
}
