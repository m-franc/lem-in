/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:45:18 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/07 20:41:43 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ft_push_back_ants(t_datas_graph *datas_graph,
		t_ants *new_ant)
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
/*
int					ft_init_way_ants(t_ants **ants, int *way_id,
		int *starts_ways_index, t_datas_graph *datas_graph)
{
	int				i;
	int				nb_ants_in_way;
	t_adj_list		**starts_ways;

	i = 0;
	starts_ways = datas_graph->adj_list[0].rooms_linked;
	if (starts_ways[*starts_ways_index]->end)
		nb_ants_in_way = datas_graph->nb_ants;
	if ((nb_ants_in_way = starts_ways[*starts_ways_index]->dist == 0))
		*starts_ways_index += 1;
	while (*ants && i < nb_ants_in_way)
	{
		(*ants)->way_id = *way_id;
		*ants = (*ants)->next;
		i++;
	}
	*way_id += 1;
	*starts_ways_index += 1;
	if (*starts_ways_index < datas_graph->adj_list[0].nb_tunnels
			&& starts_ways[*starts_ways_index]->way_id == 0)
		return (2);
	return (1);
}
*/
void				ft_init_ways_ants(t_datas_graph *datas_graph)
{
	t_ants		*ants;
	int			size_path;
	int			i;
	int			o;
	int			way_id;

	i = 0;
	o = 0;
	if (datas_graph->adj_list[0].rooms_linked[o]->end)
		size_path = datas_graph->nb_ants;
	else
		size_path = datas_graph->adj_list[0].rooms_linked[o]->dist;
	ants = datas_graph->ants;
	way_id = 1;
	while (ants)
	{
		if (i == size_path)
		{
			i = 0;
			way_id++;
			if (o < datas_graph->adj_list[0].nb_tunnels)
				size_path = datas_graph->adj_list[0].rooms_linked[o++]->dist;
			if (way_id == datas_graph->nb_ways + 1)
				way_id = 1;
		}
		ants->way_id = way_id;
		i++;
		ants = ants->next;
	}
}
