/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2017/07/11 18:24:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/07/26 19:23:06 by mfranc           ###   ########.fr       */
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
