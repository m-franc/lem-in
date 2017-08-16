/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/16 16:29:42 by mfranc           ###   ########.fr       */
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

void			ft_launch_ants_map(int *ant_number, int nb_ants, t_adj_list *first_room, int *ants_at_end)
{
	if (*ant_number == nb_ants)
		return ;
	first_room->ant_in = *ant_number;
	if (*ant_number <= nb_ants)
		*ant_number += 1;
	*ants_at_end += *ant_number;
}

void			ft_print_ants_map(int ant_num_max, t_datas_graph *datas_graph)
{
	int			index_room;
	t_adj_list	**rooms;

	index_room = -1;
	rooms = datas_graph->adj_list;
	while (index_room-- > 0)
	{
		if (rooms[index_room]->ant_in)
			ft_printf("L%s-%d", rooms[index_room]->name, rooms[index_room]->ant_in);
		if (rooms[index_room]->ant_in == ant_num_max)
			ft_putchar(' ');
		else
			break ;
	}
}

void			ft_move_ants_map(int ant_num_max, t_datas_graph *datas_graph)
{
	int			index_room;
	t_adj_list	*next_room;
	t_adj_list	**rooms;

	index_room = datas_graph->nb_rooms - 1;
	while (index_room > 0 && !rooms[index_room]->ant_in)
	{
		if (rooms[index_room]->ant_in)
		{
			next_room = ft_get_next_room(datas_graph->adj_list, rooms[index_room]);
			next_room->ant_in += rooms[index_room]->ant_in;
			rooms[index_room]->ant_in = 0;
		}
		index_room--;
	}
}

void			ft_map_crosser(int nb_ants, t_datas_graph *datas_graph)
{
	int			ant_number;
	t_adj_list	**rooms;

	ant_number = 1;
	rooms = datas_graph->adj_list;
	ft_launch_ants_map(&ant_number, nb_ants, rooms[0], &datas_graph->ants_at_end);
	while (datas_graph->adj_list[datas_graph->nb_rooms - 1]->ant_in != datas_graph->ants_at_end)
	{
		ft_move_ants_map(nb_ants + 1, datas_graph);
		ft_print_ants_map(nb_ants + 1, datas_graph);
		ft_launch_ants_map(&ant_number, nb_ants, rooms[0], &datas_graph->ants_at_end);
		if (datas_graph->adj_list[datas_graph->nb_rooms - 1]->ant_in != datas_graph->ants_at_end)
			ft_putchar('\n');
	}
}
