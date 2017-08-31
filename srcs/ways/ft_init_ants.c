/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:14:02 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/31 17:49:05 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void				ft_push_back_ants(t_datas_graph *datas_graph, t_ants *new_ant)
{
	if (datas_graph->ants)
	{
		new_ant->prev = datas_graph->last_ant;
		datas_graph->last_ant->next = new_ant;
		datas_graph->last_ant = new_ant;
	}
	else
	{
		datas_graph->ants = new_ant;
		datas_graph->last_ant = new_ant;
	}
}

t_ants				*ft_new_ant(int ant_number, t_adj_list *start_room)
{
	t_ants			*ant;

	if (!(ant = malloc(sizeof(t_ants))))
		return (NULL);
	ant->ant_number = ant_number;
	ant->curr_room = start_room;
	ant->prev_room = start_room;
	ant->comed = 0;
	ant->next = NULL;
	ant->prev = NULL;
	return (ant);
}

int					ft_init_ants(t_datas_graph *datas_graph)
{
	int				ant_number;
	int				i;
	t_ants			*new_ant;
	
	i = -1;
	ant_number = 1;
	while (++i < datas_graph->nb_ants)
	{
		if (!(new_ant = ft_new_ant(ant_number, &datas_graph->adj_list[0])))
			return (-1);
		ft_push_back_ants(datas_graph, new_ant);
		ant_number++;
	}
	return (1);
}

void				ft_init_way_ants(t_datas_graph *datas_graph)
{
	t_ants			*ants;
	int				i;
	int				nb_ants_in_way;
	int				way_id;
	t_adj_list		**starts_ways;
	int				starts_ways_index;

	i = 0;		
	starts_ways_index = 0;
	ants = datas_graph->ants;
	way_id = 1;
	nb_ants_in_way = 0;
	starts_ways = datas_graph->adj_list[0].rooms_linked;
	nb_ants_in_way = starts_ways[starts_ways_index]->dist;
	while (ants)
	{	

		if (i == nb_ants_in_way)
		{
			i = 0;
			if (way_id < datas_graph->nb_ways)
				way_id++;
			if (starts_ways_index < datas_graph->adj_list[0].nb_tunnels)
				starts_ways_index++;
			if (starts_ways[starts_ways_index]->dist == 0 && starts_ways_index < datas_graph->adj_list[0].nb_tunnels)
				starts_ways_index++;
			if (starts_ways_index == (datas_graph->adj_list[0].nb_tunnels - 1))
			{	
				way_id = 1;
				starts_ways = datas_graph->adj_list[0].rooms_linked;
				starts_ways_index = 0;
			}
			nb_ants_in_way = (*starts_ways)->dist;
		}
		ants->way_id = way_id;
		i++;
		ants = ants->next;
	}
}
