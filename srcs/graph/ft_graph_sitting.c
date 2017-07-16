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

void			ft_update_rooms_id(t_datas_graph *datas_graph)
{
	t_adj_list	**list;
	int		i;

	i = 0;
	list = datas_graph->adj_list;
	while (i < datas_graph->nb_rooms)
	{
		list[i]->id = i;
		i++;
	}
}

int			ft_prev_not_find(int index_room, char *name_room_link, t_adj_list **og_list)
{
	t_adj_list	**list;
	int		i;
	int		o;

	i = 0;
	o = 0;
	list = og_list;
	while (i < index_room)
	{
		if (ft_strequ(list[i]->name, name_room_link))
			return (0);
		i++;
	}
	return (1);
}

int			ft_get_nb_new_tunnels(t_adj_list *list_elem, t_adj_list **og_list, int index_list)
{
	int		nb_new_tunnels;
	int		i;
	t_adj_list	**last_tunnels;

	last_tunnels = list_elem->rooms_linked;	
	i = 0;
	nb_new_tunnels = 0;
	while (i < list_elem->nb_tunnels)
	{
		if (ft_prev_not_find(index_list, last_tunnels[i]->name, og_list))
			nb_new_tunnels++;
		i++;
	}
	return (nb_new_tunnels);
}

void			ft_new_tunnels(t_adj_list *elem_list, int nb_new_tunnels, t_adj_list **og_list, int index_list)
{
	int		i;
	int		o;
	t_adj_list	**last_tunnels;
	t_adj_list	**new_tunnels;
//	t_adj_list	*last_link;

	if (nb_new_tunnels == 0)
		return ;
	last_tunnels = elem_list->rooms_linked;
	new_tunnels = ft_memalloc(sizeof(t_adj_list*) * nb_new_tunnels);
	i = 0;
	o = 0;
	while (i < elem_list->nb_tunnels)
	{
		if (ft_prev_not_find(index_list, last_tunnels[i]->name, og_list))
		{
			new_tunnels[o] = ft_memalloc(sizeof(t_adj_list));
			new_tunnels[o] = ft_memcpy(new_tunnels[o], last_tunnels[i], sizeof(t_adj_list));
			o++;
		}
		i++;
	}
	i = -1;
/*	while (++i < elem_list->nb_tunnels)
	{
		last_link = last_tunnels[i];
		ft_memdel((void **)&last_link);
	}*/
//	ft_memdel((void**)last_tunnels);
	elem_list->nb_tunnels = nb_new_tunnels;
	elem_list->rooms_linked = new_tunnels;
}

int			ft_reorganize_tunnels_adj_list(t_datas_graph *datas_graph)
{
	t_adj_list	**list;
	t_adj_list	**og_list;
	t_adj_list	*elem_list;
	int		nb_new_tunnels;
	int		i;

	i = 0;
	list = datas_graph->adj_list;
	og_list = datas_graph->adj_list;
	while (i < datas_graph->nb_rooms)
	{
		elem_list = list[i];
		nb_new_tunnels = ft_get_nb_new_tunnels(list[i], og_list, i);
		ft_new_tunnels(list[i], nb_new_tunnels, og_list, i);
		i++;	
	}
	return (1);
}
