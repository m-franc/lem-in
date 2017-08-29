/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_adj_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:40:18 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/29 18:17:26 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_init_elem_list_adj(t_adj_list *elem_list, t_data_rooms *tmp_rooms, int id, int nb_tunnels)
{
	elem_list->id = id;
	if (!(elem_list->name = ft_strdup(tmp_rooms->name)))
		return (-1);
	elem_list->dist = 0;
	elem_list->ant_in = 0;
	elem_list->x = tmp_rooms->x;
	elem_list->y = tmp_rooms->y;
	elem_list->start = (tmp_rooms->start == 1) ? 1 : 0;
	elem_list->end = (tmp_rooms->end == 1) ? 1 : 0;
	elem_list->way_id = 0;
	elem_list->nb_tunnels = nb_tunnels;
	elem_list->rooms_linked = NULL;
	return (1);
}

int					ft_build_adj_list(t_data_store *data_store, t_datas_graph *datas_graph)
{
	t_data_rooms	*tmp_rooms;
	t_adj_list		*list;
	int				i;

	list = datas_graph->adj_list;
	tmp_rooms = data_store->rooms;
	i = 0;
	while (tmp_rooms)
	{
		if ((ft_init_elem_list_adj(&list[i], tmp_rooms, i, tmp_rooms->tunnels)) == -1)
			return (-1);
		tmp_rooms = tmp_rooms->next;
		i++;
	}
	return (1);
}

int					ft_get_room_by_name(t_adj_list *tunnel, char *room_to_find, t_datas_graph *datas_graph)
{
	int				i;
	t_adj_list		*list;
	
	i = 0;
	list = datas_graph->adj_list;
	while (i < datas_graph->nb_rooms)
	{
		if (ft_strequ(room_to_find, list[i].name))
		{	
			*tunnel = list[i];
			return (1);
		}
		i++;
	}
	return (-1);
}

int					ft_get_room_by_tunnels(t_adj_list *tunnel, t_tunnels *rooms_to_find, t_datas_graph *datas_graph, char *current_room)
{
	t_tunnels		*tmptmp_tunnels;

	tmptmp_tunnels = rooms_to_find;
	while (tmptmp_tunnels)
	{
		if (ft_strequ(current_room, tmptmp_tunnels->first_room) && tmptmp_tunnels->checked == 0)
		{
			tmptmp_tunnels->checked = 1;
			if ((ft_get_room_by_name(tunnel, tmptmp_tunnels->second_room, datas_graph)) == -1)
				return (-1);
			return (1);
		}
		else if (ft_strequ(current_room, tmptmp_tunnels->second_room) && tmptmp_tunnels->checked == 0)
		{	
			tmptmp_tunnels->checked = 1;
			if ((ft_get_room_by_name(tunnel, tmptmp_tunnels->first_room, datas_graph)) == -1)
				return (-1);
			return (1);
		}
		tmptmp_tunnels = tmptmp_tunnels->next;
	}
	return (-1);
}

int					ft_get_nb_tunnels(t_tunnels *tmp_tunnels, char *current_room)
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
		else if (ft_strequ(tmptmp_tunnels->first_room, current_room) && tmptmp_tunnels->checked == 0)
		{
			tmptmp_tunnels->checked = 1;
			nb_tunnels++;
		}
		else if (ft_strequ(tmptmp_tunnels->second_room, current_room) && tmptmp_tunnels->checked == 0)
		{	
			tmptmp_tunnels->checked = 1;
			nb_tunnels++;	
		}
		tmptmp_tunnels = tmptmp_tunnels->next;
	}
	return (nb_tunnels);
}

void				ft_reset_checked_tunnels(t_tunnels *tmp_tunnels)
{
	t_tunnels		*tmptmp_tunnels;

	tmptmp_tunnels = tmp_tunnels;
	while (tmptmp_tunnels)
	{
		tmptmp_tunnels->checked = 0;
		tmptmp_tunnels = tmptmp_tunnels->next;
	}
}

t_adj_list			*ft_init_rooms_linked(t_tunnels *tmp_tunnels, t_datas_graph *datas_graph, int nb_tunnels, char *current_room)
{
	int				i;
	t_adj_list		*rooms_linked;

	i = -1;
	if (nb_tunnels == 0)
		return (NULL);
	if (!(rooms_linked = ft_memalloc(sizeof(t_adj_list) * nb_tunnels)))
		return (NULL);
	while (++i < nb_tunnels)
	{	
		if ((ft_get_room_by_tunnels(&rooms_linked[i], tmp_tunnels, datas_graph, current_room)) == -1)
			return (NULL);
	}
	return (rooms_linked);
}

int					ft_build_tunnels_adj_list(t_tunnels *tunnels, t_datas_graph *datas_graph)
{
	t_adj_list		*list;
	t_tunnels		*tmp_tunnels;
	int				i;
	int				no_link;

	list = datas_graph->adj_list;
	i = 0;
	no_link = 0;
	while (i < datas_graph->nb_rooms)
	{
		tmp_tunnels = tunnels;
		ft_reset_checked_tunnels(tmp_tunnels);
		if ((list[i].nb_tunnels = ft_get_nb_tunnels(tmp_tunnels, list[i].name)) == -1)
			return (-1);
		ft_reset_checked_tunnels(tmp_tunnels);
		if (!(list[i].rooms_linked = ft_init_rooms_linked(tmp_tunnels, datas_graph, list[i].nb_tunnels, list[i].name)))
			no_link++;
		i++;
	}
	if (no_link == (datas_graph->nb_rooms -1))
		return (-1);
	return (1);
}
