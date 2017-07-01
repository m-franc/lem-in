/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:53:53 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 16:05:56 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void				ft_put_data_parsed(t_data_store *data_store)
{
	t_tunnels		*tunnels;
	t_data_rooms	*rooms;

	tunnels = data_store->tunnels;
	rooms = data_store->rooms;
	if (tunnels)
	{
		ft_putstrcolor("TUNNELS : \n", CYAN);
		while (tunnels)
		{
			ft_printf("{grey}%s{eoc} - {grey}%s{eoc}\n", tunnels->first_room, tunnels->second_room);
			tunnels = tunnels->next;
		}
	}
	ENDL
	if (rooms)
	{
		ft_putstrcolor("ROOMS : \n", CYAN);
		while (rooms)
		{
			if (rooms->start)
				ft_printf("{grey}%s{eoc} | coords : {blue}%d %d {eoc} | {green}start{eoc}\n", rooms->name, rooms->x, rooms->y, rooms->start);
			else if (rooms->end)
				ft_printf("{grey}%s{eoc} | coords : {blue}%d %d {eoc} | {green}end{eoc}\n", rooms->name, rooms->x, rooms->y, rooms->end);
			else
				ft_printf("{grey}%s{eoc} | coords : {blue}%d %d {eoc}\n", rooms->name, rooms->x, rooms->y);
			ft_putlist(rooms->rooms_linked);
			rooms = rooms->next;
		}
	}
}
