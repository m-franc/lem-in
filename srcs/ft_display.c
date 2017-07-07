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

void	ft_put_adj_list(t_data_store *data_store, t_datas_graph *datas_graph)
{
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
				if (i != (rooms->tunnels - 1))
					ft_putstr(", ");	
				i++;
			}
			ft_putchar('\n');
		}
		o++;
		rooms = rooms->next;
	}
}
