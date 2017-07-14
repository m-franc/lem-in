/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_second_room.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:55:26 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/13 20:56:58 by mfranc           ###   ########.fr       */
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
}

t_adj_list		*ft_new_room_way(t_adj_list *content_elem_list)
{
	t_adj_list	*new_room;

	new_room = ft_memalloc(sizeof(t_adj_list));
	new_room = ft_memcpy(new_room, content_elem_list, sizeof(t_adj_list));
	return (new_room);
}

void			ft_init_second_room(t_datas_graph *datas_graph)
{
	t_adj_list	**second_rooms_ways;
	t_adj_list	*new_room;
	t_ways		*ways;
	int		i;

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
