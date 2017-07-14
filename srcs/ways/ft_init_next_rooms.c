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

t_adj_list		*ft_get_current_last_room_way(t_ways *way)
{
	t_adj_list	*tmp_rooms;
	
	tmp_rooms = way->rooms;
	while (tmp_rooms && tmp_rooms->next)
		tmp_rooms = tmp_rooms->next;
	return (tmp_rooms);
}

/*void			ft_way_dup(t_ways *way_src)
{
	t_ways		*way_dest;
	t_ways		*way_dest_tmp;
	
	way_dest = NULL;
	way_dest_tmp = way_dest;
}
*/
void			ft_init_next_rooms(t_datas_graph *datas_graph, t_ways *way)
{
	t_adj_list	*last_room;	
	t_adj_list	**last_room_rooms_linked;
	t_adj_list	*new_room;
//	t_ways		*new_way;
	int		o;

	last_room = ft_get_current_last_room_way(way);
	last_room_rooms_linked = datas_graph->adj_list[last_room->id]->rooms_linked;	
	o = 0;
	while (o < datas_graph->adj_list[last_room->id]->nb_tunnels)
	{
		new_room = ft_new_room_way(last_room_rooms_linked[o]);
		ft_push_back_room_way(datas_graph->ways, new_room);
		o += 1;
	}
}
