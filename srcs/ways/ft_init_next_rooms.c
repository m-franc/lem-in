/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_next_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   updated: 2017/07/13 20:54:26 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_push_back_room_way(t_ways *way, t_adj_list *next_room)
{
	t_adj_list	*tmp_rooms;

	tmp_rooms = way->rooms;
	while (tmp_rooms && tmp_rooms->next)
		tmp_rooms = tmp_rooms->next;
	tmp_rooms->next = next_room;
	way->nb_rooms++;
}

t_adj_list		*ft_new_room_way(t_adj_list *content_elem_list)
{
	t_adj_list	*new_room;

	new_room = ft_memalloc(sizeof(t_adj_list));
	new_room = ft_memcpy(new_room, content_elem_list, sizeof(t_adj_list));
	return (new_room);
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

	tmp_og_ways = og_ways;
	while (tmp_og_ways && tmp_og_ways->next && tmp_og_ways->id != nway)
		tmp_og_ways = tmp_og_ways->next;
	if (!tmp_og_ways->next)
		tmp_og_ways->next = new_way;
	else
	{
		tmp_next_ways = tmp_og_ways->next;
		tmp_og_ways->next = new_way;
		new_way->next = tmp_next_ways;
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

void			ft_init_multiple_next_rooms(t_datas_graph *datas_graph, t_adj_list *last_room, t_adj_list **last_room_rooms_linked, t_ways *way)
{
	int		o;
	t_ways		*new_way;
	t_adj_list	*new_room;

	o = 0;
	while (o < datas_graph->adj_list[last_room->id]->nb_tunnels)
	{
		new_room = ft_new_room_way(last_room_rooms_linked[o]);
		ft_push_back_room_way(way, new_room);
		new_way = ft_way_dup(way);
		ft_push_back_after_nway(datas_graph->ways, new_way, way->id);
		ft_update_ways_id(datas_graph->ways);
		o += 1;
	}
}

void			ft_init_next_rooms(t_datas_graph *datas_graph, t_ways *way)
{
	t_adj_list	*last_room;	
	t_adj_list	**last_room_rooms_linked;
	t_adj_list	*new_room;

	last_room = ft_get_current_last_room_way(way);
	last_room_rooms_linked = datas_graph->adj_list[last_room->id]->rooms_linked;	
	if (datas_graph->adj_list[last_room->id]->nb_tunnels == 0)
		return ;
	else if (datas_graph->adj_list[last_room->id]->nb_tunnels > 1)
		ft_init_multiple_next_rooms(datas_graph, last_room, last_room_rooms_linked, way);
	else
	{
		new_room = ft_new_room_way(last_room_rooms_linked[0]);
		ft_push_back_room_way(way, new_room);
	}
}
