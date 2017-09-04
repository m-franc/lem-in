/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tunnels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:06:48 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/04 14:40:30 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_adj_list			*ft_get_room_by_name(char *room_to_find,
		t_datas_graph *datas_graph)
{
	int				i;
	t_adj_list		*list;

	i = 0;
	list = datas_graph->adj_list;
	while (i < datas_graph->nb_rooms)
	{
		if (ft_strequ(room_to_find, list[i].name))
			return (&list[i]);
		i++;
	}
	return (NULL);
}

t_adj_list			*ft_get_room_by_tunnels(t_tunnels *rooms_to_find,
		t_datas_graph *datas_graph, char *current_room)
{
	t_tunnels		*tmptmp_tunnels;

	tmptmp_tunnels = rooms_to_find;
	while (tmptmp_tunnels)
	{
		if (ft_strequ(current_room, tmptmp_tunnels->first_room)
				&& tmptmp_tunnels->checked == 0)
		{
			tmptmp_tunnels->checked = 1;
			return (ft_get_room_by_name(tmptmp_tunnels->second_room,
						datas_graph));
		}
		else if (ft_strequ(current_room, tmptmp_tunnels->second_room)
				&& tmptmp_tunnels->checked == 0)
		{
			tmptmp_tunnels->checked = 1;
			return (ft_get_room_by_name(tmptmp_tunnels->first_room,
						datas_graph));
		}
		tmptmp_tunnels = tmptmp_tunnels->next;
	}
	return (NULL);
}

int					ft_get_nb_tunnels(t_tunnels *tmp_tunnels,
		char *current_room)
{
	int				nb_tunnels;
	t_tunnels		*tmptmp_tunnels;

	nb_tunnels = 0;
	tmptmp_tunnels = tmp_tunnels;
	while (tmptmp_tunnels)
	{
		if (ft_strequ(tmptmp_tunnels->first_room, current_room)
			&& ft_strequ(tmptmp_tunnels->second_room, current_room))
			return (-1);
		else if (ft_strequ(tmptmp_tunnels->first_room, current_room)
				&& tmptmp_tunnels->checked == 0)
		{
			tmptmp_tunnels->checked = 1;
			nb_tunnels++;
		}
		else if (ft_strequ(tmptmp_tunnels->second_room, current_room)
				&& tmptmp_tunnels->checked == 0)
		{
			tmptmp_tunnels->checked = 1;
			nb_tunnels++;
		}
		tmptmp_tunnels = tmptmp_tunnels->next;
	}
	return (nb_tunnels);
}

t_adj_list			**ft_init_rooms_linked(t_tunnels *tmp_tunnels,
		t_datas_graph *datas_graph, int nb_tunnels, char *current_room)
{
	int				i;
	t_adj_list		**rooms_linked;

	i = -1;
	if (nb_tunnels == 0)
		return (NULL);
	if (!(rooms_linked = ft_memalloc(sizeof(t_adj_list*) * nb_tunnels)))
		return (NULL);
	while (++i < nb_tunnels)
	{
		if (!(rooms_linked[i] = ft_get_room_by_tunnels(tmp_tunnels,
						datas_graph, current_room)))
			return (NULL);
	}
	return (rooms_linked);
}
