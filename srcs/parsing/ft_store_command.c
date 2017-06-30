/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:27:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 19:25:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int				ft_store_tunnel(t_data_store *data_store, char *first_room, char *second_room)
{
	t_tunnels	*new_tunnel;
	t_tunnels	*last_tunnels;

	if (!(new_tunnel = (t_tunnels*)malloc(sizeof(t_tunnels))))
		exit(-1);
	new_tunnel->first_room = first_room;
	new_tunnel->second_room = second_room;
	new_tunnel->next = NULL;
	last_tunnels = data_store->tunnels;
	if (!last_tunnels)
		ft_push_back_tunnel(&data_store->tunnels, new_tunnel);
	else
		ft_push_back_tunnel(&last_tunnels, new_tunnel);
	data_store->nb_tunnels++;
	return (1);
}

int				ft_store_ants_number(t_data_store *data_store, char *ants_number)
{
	long long	nb_ants;

	nb_ants = ft_atoi(ants_number);
	data_store->nb_ants = nb_ants;
	return (1);
}

int				ft_store_modif_command(t_data_store *data_store, char *line)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##START") == 0)
	{
		if (data_store->start_mark > 1)
			return (-1);
		if (data_store->start_mark == 0)
			data_store->start_mark++;
	}
	else if (ft_strcmp(line, "##end") == 0 || ft_strcmp(line, "##END") == 0)
	{
		if (data_store->end_mark > 1)
			return (-1);
		if (data_store->end_mark == 0)
			data_store->end_mark++;	
	}
	return (1);
}

static int		ft_init_start_end(t_data_store *data_store, t_data_rooms *new_room)
{
	if (data_store->start_mark == 1 && data_store->end_mark == 1)
		return (-1);	
	new_room->start = 0;
	new_room->end = 0;
	if (data_store->start_mark == 1)
	{
		new_room->start = 1;
		data_store->start_mark++;
	}
	if (data_store->end_mark == 1)
	{
		new_room->end = 1;
		data_store->end_mark++;	
	}
	return (1);
}

int					ft_store_room(t_data_store *data_store, char **data_room)
{
	t_data_rooms	*last_rooms;
	t_data_rooms	*new_room;

	last_rooms = data_store->rooms;
	if (!ft_check_duplicate(last_rooms, data_room))	
		return (0);	
	last_rooms = data_store->rooms;
	if (!(new_room = (t_data_rooms*)malloc(sizeof(t_data_rooms))))
		exit(-1);
	new_room->name = data_room[0];
	new_room->tunnels = 0;
	if ((ft_init_start_end(data_store, new_room)) == -1)
		return (-1);
	new_room->x = ft_atoi(data_room[1]);
	new_room->y = ft_atoi(data_room[2]);
	new_room->next = NULL;
	if (!last_rooms)
		data_store->rooms = new_room;
	else
		ft_push_back_room(&last_rooms, new_room);
	data_store->nb_rooms++;
	return (1);
}
