/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:28:01 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 19:25:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_check_duplicate(t_data_rooms *last_rooms, char **data_room)
{
	if (!last_rooms)
		return (1);
	while (last_rooms)
	{
		if (ft_strcmp(last_rooms->name, data_room[0]) == 0
				&& last_rooms->x == ft_atoi(data_room[1])
				&& last_rooms->y == ft_atoi(data_room[2]))
			return (-1);
		else if (ft_strcmp(last_rooms->name, data_room[0]) != 0
				&& last_rooms->x == ft_atoi(data_room[1])
				&& last_rooms->y == ft_atoi(data_room[2]))
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
