/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_next_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/19 20:07:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_push_back_room_way(t_ways *way, t_adj_list *next_room)
{
	t_adj_list	*tmp_rooms;
	t_adj_list	*prev;

	tmp_rooms = way->rooms;
	while (tmp_rooms && tmp_rooms->next)
	{
		tmp_rooms = tmp_rooms->next;
		prev = tmp_rooms;
	}
	tmp_rooms->next = next_room;
	next_room->prev = tmp_rooms;
	way->nb_rooms++;
}

t_adj_list		*ft_get_current_last_room_way(t_ways *way)
{
	t_adj_list	*tmp_rooms;

	tmp_rooms = way->rooms;
	while (tmp_rooms && tmp_rooms->next)
		tmp_rooms = tmp_rooms->next;
	return (tmp_rooms);
}

t_ways			*ft_way_dup(t_ways *way_src)
{
	t_ways		*way_dest;
	t_ways		*way_dest_tmp;
	t_adj_list	*rooms_src;
	t_adj_list	*rooms_dest; 

	rooms_src = way_src->rooms;
	way_dest_tmp = ft_new_way(rooms_src, way_src->id);
	way_dest = way_dest_tmp;
	rooms_dest = way_dest_tmp->rooms;
	rooms_src = rooms_src->next;
	while (rooms_src)
	{
		rooms_dest->next = ft_new_room_way(rooms_src);
		rooms_dest = rooms_dest->next;
		rooms_src = rooms_src->next;
	}
	return (way_dest);
}

void			ft_push_back_after_nway(t_ways *og_ways, t_ways *new_way, int nway)
{
	t_ways		*tmp_og_ways;
	t_ways		*tmp_next_ways;
	t_ways		*tmp_prev_ways;

	tmp_og_ways = og_ways;
	while (tmp_og_ways && tmp_og_ways->next && tmp_og_ways->id != nway)
	{
		tmp_og_ways = tmp_og_ways->next;
		tmp_prev_ways = tmp_og_ways;
	}
	if (!tmp_og_ways->next)
	{
		tmp_og_ways->next = new_way;
		new_way->prev = tmp_prev_ways;	
	}
	else
	{
		tmp_next_ways = tmp_og_ways->next;
		tmp_og_ways->next = new_way;
		new_way->next = tmp_next_ways;
		new_way->prev = tmp_prev_ways;
	}
}

void			ft_update_ways_id(t_ways *ways)
{
	int		i;
	t_ways		*tmp_ways;

	i = 0;
	tmp_ways = ways;
	while (tmp_ways)
	{
		tmp_ways->id = i;
		i++;
		tmp_ways = tmp_ways->next;
	}	
}

int				ft_get_antecedant(t_adj_list *current_room, t_ways *ways)
{
	t_adj_list	*rooms;

	rooms = ways->rooms;
	while (rooms)
	{
		if (ft_strequ(rooms->name, current_room->name))
			return (1);
		rooms = rooms->next;
	}
	return (0);
}

void			ft_swap_rooms_linked(t_adj_list *room)
{
	t_adj_list	*tmp;

	tmp = room->rooms_linked[0];
	room->rooms_linked[0] = room->rooms_linked[room->nb_tunnels - 1];
	room->rooms_linked[room->nb_tunnels - 1] = tmp;
}

t_adj_list		*ft_get_same_room(t_ways *way, char *same_room)
{
	t_adj_list	*rooms;

	if (!way)
		return (NULL);
	rooms = way->rooms;
	while (rooms && rooms->next)
	{
		if (ft_strequ(rooms->name, same_room))
			return (rooms);
		rooms = rooms->next;
	}
	return (NULL);
}


int				ft_init_next_rooms(t_datas_graph *datas_graph, t_adj_list *last_room, t_ways *way)
{
	t_adj_list	**last_room_rooms_linked;
	t_adj_list	*new_room;
	t_adj_list	*first_room;
	int			o;
	int			i;

	last_room_rooms_linked = last_room->rooms_linked;
}

void			ft_init_second_room(t_datas_graph *datas_graph)
{
	t_adj_list	**second_rooms_ways;
	t_adj_list	*new_room;
	t_ways		*ways;
	int			i;

	ways = datas_graph->ways;
	second_rooms_ways = datas_graph->adj_list[0]->rooms_linked;
	i = 0;
	while (i < datas_graph->adj_list[0]->nb_tunnels && ways)
	{	
		new_room = ft_new_room_way(second_rooms_ways[i]);
		ft_push_back_room_way(ways, new_room);
		ways = ways->next;
		i++;
	}
}
