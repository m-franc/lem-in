/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:28:01 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 19:31:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_check_duplicate(t_data_rooms *last_rooms, char **data_room)
{
	if (!last_rooms)
		return (1);
	while (last_rooms)
	{
		if (ft_strcmp(last_rooms->name, data_room[0]) == 0)
			return (-1);
		last_rooms = last_rooms->next;
	}
	return (1);
}

int		ft_str_is_room(char *room)
{
	if (room[0] == 76 || room[0] == 35 || ft_strlen(room) == 0
			|| ft_strchr(room, ' '))
		return (0);
	else
		return (1);
}

int		ft_check_data_room(char **tab)
{
	if (ft_tablen(tab) != 3
		|| !ft_str_is_room(tab[0])
		|| ft_strchr(tab[0], '-')
		|| !ft_str_isdigit(tab[1])
		|| !ft_str_isdigit(tab[2]))
		return (0);
	else
		return (1);
}

int		ft_add_rooms_linked(t_data_rooms *rooms, char *first_room, char *second_room)
{
	t_list	*new_room_linked;
	t_list	*last_rooms_linked;

	last_rooms_linked = rooms->rooms_linked;
	if (ft_strcmp(rooms->name, first_room) == 0
			&& ft_strcmp(rooms->name, second_room) == 0) 
		return (-1);
	else if (ft_strcmp(rooms->name, first_room) == 0)
		new_room_linked = ft_lstnew(second_room, ft_strlen(second_room) + 1);
	else if (ft_strcmp(rooms->name, first_room) == 0)
		new_room_linked = ft_lstnew(first_room, ft_strlen(first_room) + 1);
	else
		return (0);
	if (!last_rooms_linked)
		ft_push_back_room_linked(&rooms->rooms_linked, new_room_linked);
	else
		ft_push_back_room_linked(&last_rooms_linked, new_room_linked);
	rooms->tunnels++;
	return (1);
}

int		ft_check_room_tunnel(t_data_store *data_store)
{
	t_data_rooms	*rooms;
	t_tunnels		*tunnels;

	rooms = data_store->rooms;
	while (rooms)
	{
		tunnels = data_store->tunnels;
		while (tunnels)
		{
			if ((ft_add_rooms_linked(rooms, tunnels->first_room,
						tunnels->second_room)) == -1)
				return (-1);
			tunnels = tunnels->next;
		}
		rooms = rooms->next;
	}
	return (1);
}
