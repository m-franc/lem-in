/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:53:53 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/06 11:09:05 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ft_put_data_tunnel(t_tunnels *tunnels)
{
	ft_putstrcolor("TUNNELS : \n", CYAN);
	while (tunnels)
	{
		ft_printf("{grey}%s{eoc} - {grey}%s{eoc}\n",
				tunnels->first_room, tunnels->second_room);
		tunnels = tunnels->next;
	}
}

void				ft_put_data_room(t_data_rooms *rooms)
{
	ft_putstrcolor("ROOMS : \n", CYAN);
	while (rooms)
	{
		if (rooms->start)
			ft_printf("{grey}%s{eoc} | {blue}%d %d {eoc} | {green}start{eoc}\n",
					rooms->name, rooms->x, rooms->y, rooms->start);
		else if (rooms->end)
			ft_printf("{grey}%s{eoc} | {blue}%d %d {eoc} | {green}end{eoc}\n",
					rooms->name, rooms->x, rooms->y, rooms->end);
		else
			ft_printf("{grey}%s{eoc} | {blue}%d %d {eoc}\n",
					rooms->name, rooms->x, rooms->y);
		ft_putlist(rooms->rooms_linked);
		rooms = rooms->next;
	}
}

void				ft_put_data_parsed(t_data_store *data_store)
{
	t_tunnels		*tunnels;
	t_data_rooms	*rooms;

	tunnels = data_store->tunnels;
	rooms = data_store->rooms;
	if (tunnels)
		ft_put_data_tunnel(tunnels);
	ft_putchar('\n');
	if (rooms)
		ft_put_data_room(rooms);
}

void				ft_put_adj_list_elem(t_adj_list *list, int o)
{
	int				i;
	t_adj_list		**tmp_list;

	ft_printf("{grey}%s{eoc} (dist : {purple}%d{eoc}, chemin : {red}%d{eoc})",
			list[o].name, list[o].dist, list[o].way_id);
	if (!list[o].rooms_linked)
		ft_putchar('\n');
	else
	{
		ft_putstr(" -> ");
		i = 0;
		tmp_list = list[o].rooms_linked;
		while (i < list[o].nb_tunnels)
		{
			ft_printf("{cyan}%s{eoc}", tmp_list[i]->name);
			if (i != (list[o].nb_tunnels - 1))
				ft_putstr(", ");
			i++;
		}
		ft_putchar('\n');
	}
}

void				ft_put_adj_list(t_datas_graph *datas_graph)
{
	int				o;
	t_adj_list		*list;

	o = 0;
	ft_putstrcolor("ajdacences\'s distances list\n", GREEN);
	list = datas_graph->adj_list;
	while (o < datas_graph->nb_rooms)
	{
		ft_put_adj_list_elem(list, o);
		o++;
	}
	ft_putchar('\n');
}
