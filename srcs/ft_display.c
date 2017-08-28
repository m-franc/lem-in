/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:53:53 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/28 11:24:47 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


void			ft_put_ants(t_ants *ants)
{
	t_ants	*tmp_ants;

	tmp_ants = ants;
	//	ft_putstrcolor("LISTE DES FOURMIS\n", GREEN);
	while (tmp_ants)
	{
		ft_printf("ant Num : {cyan}%d{eoc}, room : {red}%s{eoc}, way : {grey}%d{eoc}\n", tmp_ants->ant_number, tmp_ants->curr_room->name, tmp_ants->way_id);
		tmp_ants = tmp_ants->next;
	}
	ENDL
}

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

void	ft_put_adj_list(t_datas_graph *datas_graph)
{
	int o = 0;
	int i = 0;
	t_adj_list **list = datas_graph->adj_list;
	ft_putstrcolor("ajdacences\'s list\n", GREEN);
	while (o < datas_graph->nb_rooms)
	{
		ft_printf("{grey}%s{eoc}", list[o]->name);
		if (!list[o]->rooms_linked)
			ft_putchar('\n');
		else
		{
			ft_putstr(" -> ");
			i = 0;
			t_adj_list **tmp_list = list[o]->rooms_linked;
			while (i < list[o]->nb_tunnels)
			{
				ft_printf("{cyan}%s{eoc}", tmp_list[i]->name);
				if (i != (list[o]->nb_tunnels - 1))
					ft_putstr(", ");	
				i++;
			}
			ft_putchar('\n');
		}
		o++;
	}
}

void	ft_put_adj_list_dist(t_datas_graph *datas_graph)
{
	int o = 0;
	int i = 0;
	t_adj_list **list = datas_graph->adj_list;
	ft_putstrcolor("ajdacences\'s distances list\n", GREEN);
	while (o < datas_graph->nb_rooms)
	{
		if (list[o]->end)
			ft_printf("{green}%s{eoc}\n", list[o]->name);
		else
		{
			ft_printf("{grey}%s{eoc} (dist before end : {purple}%d{eoc}, chemin : {red}%d{eoc})", list[o]->name, list[o]->dist, list[o]->way_id);
			if (!list[o]->rooms_linked)
				ft_putchar('\n');
			else
			{
				ft_putstr(" -> ");
				i = 0;
				t_adj_list **tmp_list = list[o]->rooms_linked;
				while (i < list[o]->nb_tunnels)
				{
					ft_printf("{cyan}%s{eoc}", tmp_list[i]->name);
					if (i != (list[o]->nb_tunnels - 1))
						ft_putstr(", ");	
					i++;
				}
				ft_putchar('\n');
			}

		}
		o++;
	}
}

void		ft_put_adj_matrix(t_datas_graph *datas_graph)
{
	int		**matrix;
	int		i;
	int		o;

	matrix = datas_graph->adj_matrix;
	i = 0;
	ft_putstrcolor("AJDACENCES\'S MATRIX\n", GREEN);
	while (i < datas_graph->nb_rooms)
	{
		o = 0;
		while (o < datas_graph->nb_rooms)
		{
			if (matrix[i][o])
				ft_printf("{cyan}%d{eoc} ", matrix[i][o]);
			else	
				ft_printf("{grey}%d{eoc} ", matrix[i][o]);
			o++;
		}
		ENDL
			i++;
	}
}

/*void			ft_put_ways(t_ways *ways)
  {
  t_ways		*tmp_ways;
  t_adj_list	*rooms;

  tmp_ways = ways;
  while (tmp_ways)
  {
  rooms = tmp_ways->rooms;
  while (rooms && rooms->next)
  {
  ft_printf("{red}%s{eoc} -> ", rooms->name);
  rooms = rooms->next;
  }
  if (rooms)
  {
  ft_printf("{red}%s{eoc}", rooms->name);
  rooms = rooms->next;	
  }
  ENDL
  tmp_ways = tmp_ways->next;
  }
  }*/
