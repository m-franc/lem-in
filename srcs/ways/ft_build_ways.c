/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/17 16:12:45 by mfranc           ###   ########.fr       */
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

/*void			ft_print_ants_map(int ant_num_max, t_datas_graph *datas_graph)
{
	int			index_room;
	t_adj_list	**rooms;

	index_room = -1;
	rooms = datas_graph->adj_list;
	while (++index_room < datas_graph->nb_)
	{
		if (rooms[index_room]->ant_in)
		if (rooms[index_room]->ant_in != ant_num_max)
			ft_putchar(' ');
		else
			break ;
	}
}*/

void			ft_move_ants_map(t_datas_graph  *datas_graph)
{
	int			i;
	t_adj_list	**next_room;
	t_ants		**ants;

	i = 0;
	ants = datas_graph->ants;
	while (i < datas_graph->nb_ants)
	{
		next_room = ants[i]->curr_room->rooms_linked;
		if (next_room[0]->ant_in == 0 || next_room[0]->end)
		{
			next_room[0]->ant_in += ants[i]->ant_number;
			ants[i]->curr_room->ant_in = 0;
			ants[i]->curr_room = next_room[0];
			ft_printf("L%s-%d", ants[i]->curr_room->name, ants[i]->ant_number);
			if (i != (datas_graph->nb_ants - 1))
				ft_putchar(' ');
			else
				ft_putchar('\n');
		}
		i++;
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
	t_ants		**ants;
	t_adj_list	**rooms;
	t_adj_list	*end_room;

	ants = datas_graph->ants;
	rooms = datas_graph->adj_list;
	end_room = datas_graph->adj_list[datas_graph->nb_rooms - 1];
	datas_graph->ants_at_end = ft_init_ants_at_end(ants, datas_graph->nb_ants);
	while (end_room->ant_in != datas_graph->ants_at_end)
		ft_move_ants_map(datas_graph);
}
