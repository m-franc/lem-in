/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:39:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/20 15:06:20 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void			ft_sort_link_room(t_adj_list *room)
{
	t_adj_list	**links;
	t_adj_list	*tmp_link;
	int			j;

	j = 0;
	links = rooms[i]->rooms_linked;
	while (j < rooms[i]->nb_tunnels - 1)
	{
		while (links[j]->dist > links[j + 1]->dist)
		{
			tmp_link = links[j];
			links[j] = links[j + 1];
			links[j + 1] = tmp_link;
			j = 0;
		}
		j++;
	}
}

void	ft_init_ways(t_datas_graph *datas_graph)
{
	int			way_id;
	int			i;
	t_adj_list	*next_room;
	t_adj_list	*start_room;

	way_id = 1;
	i = -1;
	start_room = datas_graph->adj_list[0];
	ft_sort_link_room(start_room);
	while (++i < start_room->nb_tunnels)
	{

	}
}
