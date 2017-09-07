/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tunnels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:20:47 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/07 19:19:13 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_del_tunnel(t_tunnels **tunnel, t_tunnels **prev)
{
	t_tunnels	*to_free;

	to_free = *tunnel;
	*tunnel = (*tunnel)->next;
	if (prev)
		(*prev)->next = *tunnel;
	ft_strdel(&to_free->first_room);
	ft_strdel(&to_free->second_room);
	ft_memdel((void**)&to_free);
}

int				ft_tunnels_matched(t_tunnels *og_tunnels,
		t_tunnels *curr_tunnel)
{
	if ((ft_strequ(curr_tunnel->first_room, og_tunnels->first_room)
		&& ft_strequ(curr_tunnel->second_room, og_tunnels->second_room))
		|| (ft_strequ(curr_tunnel->first_room, og_tunnels->second_room)
		&& ft_strequ(curr_tunnel->second_room, og_tunnels->first_room))
		|| (ft_strequ(curr_tunnel->second_room, og_tunnels->first_room)
		&& ft_strequ(curr_tunnel->first_room, og_tunnels->second_room)))
		return (1);
	else
		return (0);
}

void			ft_find_duplicate(t_tunnels *curr_tunnel, t_tunnels *og_tunnels)
{
	t_tunnels	*prev;

	prev = NULL;
	while (og_tunnels)
	{
		if (curr_tunnel != og_tunnels
				&& ft_tunnels_matched(og_tunnels, curr_tunnel))
			ft_del_tunnel(&og_tunnels, &prev);
		else
		{
			prev = og_tunnels;
			og_tunnels = og_tunnels->next;
		}
	}
}

void			ft_check_tunnels(t_data_store *data_store)
{
	t_tunnels	*og_tunnels;
	t_tunnels	*curr_tunnel;

	curr_tunnel = data_store->tunnels;
	while (curr_tunnel)
	{
		og_tunnels = data_store->tunnels;
		ft_find_duplicate(curr_tunnel, og_tunnels);
		curr_tunnel = curr_tunnel->next;
	}
}
