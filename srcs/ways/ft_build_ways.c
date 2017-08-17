/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/17 13:20:57 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_init_dist(t_adj_list *current_room, int dist)
{
	t_adj_list	**next_rooms;
	int			i;

	current_room->dist = dist;
	if (current_room->start == 1)
		return ;
	i = -1;
	next_rooms = current_room->rooms_linked;
	while (++i < current_room->nb_tunnels)
	{
		if (!next_rooms[i]->end)
			if (!next_rooms[i]->dist || next_rooms[i]->dist > (dist + 1))
				ft_init_dist(next_rooms[i], dist + 1);
	}
}

t_adj_list		*ft_get_next_room(t_adj_list **og_rooms, t_adj_list *curr_room)
{
	int			nb_tunnels;
	int			shortter_to_end_room;

	nb_tunnels = curr_room->nb_tunnels;
	shortter_to_end_room = 2147483647;
	while (nb_tunnels-- > 0)
	{
		if ((shortter_to_end_room > curr_room->rooms_linked[nb_tunnels]->dist)
				&& curr_room->rooms_linked[nb_tunnels]->dist > 0)
			shortter_to_end_room = curr_room->rooms_linked[nb_tunnels]->id;
	}
	if (shortter_to_end_room == 2147483647)
		return (NULL);
	return (og_rooms[shortter_to_end_room]);
}

int				ft_ant_in_map(t_datas_graph *datas_graph)
{
	int			i;

	i = 0;
	while (i < datas_graph->nb_rooms && datas_graph->adj_list[i]->ant_in)
		i++;
	if (i != datas_graph->nb_rooms)
		return (0);
	else
		return (1);
}

void			ft_launch_ants_map(int *ant_number, int nb_ants, t_adj_list *first_room)
{
	if (*ant_number == nb_ants)
		return ;
	first_room->ant_in = *ant_number;
	if (*ant_number <= nb_ants)
		*ant_number += 1;
}

void			ft_print_ants_map(int ant_num_max, t_datas_graph *datas_graph)
{
	int			index_room;
	t_adj_list	**rooms;

	index_room = -1;
	rooms = datas_graph->adj_list;
	while (++i < datas_graph)
	{
		if (rooms[index_room]->ant_in)
			ft_printf("L%s-%d", rooms[index_room]->name, rooms[index_room]->ant_in);
		if (rooms[index_room]->ant_in != ant_num_max)
			ft_putchar(' ');
		else
			break ;
	}
}

void			ft_move_ants_map(int ant_num_max, t_datas_graph  *datas_graph)
{
	int			i;
	t_adj_list	**next_room;
	t_ants		**ants;
	t_adj_list	**rooms;

	i = 0;
	while (i < datas_graph->nb_ants)
	{
		next_rooms = ants->rooms->rooms_linked;
		while (ants->rooms->rooms_linked)
		{
			if (next_room->ant_in == ant_num_max)
				break ;
		}
		rrsssdddd;
	}
}

int				ft_init_ants_at_end(t_ants **ants, int nb_ants)
{
	int			ants_at_end;
	int			i;

	i = -1;
	ants_at_end = 0;
	while (++i < nb_ants)
		ants_at_end += ants[i]->ant_number;
	return (ants_at_end);
}

void			ft_map_crosser(t_datas_graph *datas_graph)
{
	int			ant_number;
	t_ants		**ants;
	t_adj_list	**rooms;
	t_ajd_list	*end_room;

	ants = datas_graph->ants;
	rooms = datas_graph->adj_list;
	end_room = datas_graph->adj_list[datas_graph->nb_rooms - 1];
	datas_graph->ants_at_end = ft_init_ants_at_end(ants, datas_graph->nb_ants);
	while (end_room->ant_in != datas_graph->ants_at_end)
	{
		ft_move_ants_map(datas_graph->nb_ants + 1, datas_graph);
		ft_print_ants_map(datas_graph->nb_ants + 1, datas_graph);
		if (end_room->ant_in != datas_graph->ants_at_end)
			ft_putchar('\n');
	}
}
