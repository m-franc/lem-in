/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:27:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/29 13:15:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_store_tunnel(t_data_store *data_store, char *first_room, char *second_room)
{
	t_tunnels	*new_tunnel;
	
	if (!(new_tunnel = (t_tunnels*)malloc(sizeof(t_tunnels))))
		exit(-1);
	new_tunnel->first_room = first_room;
	new_tunnel->second_room = second_room;
	ft_putendl("*&(&*(&*()))");
	ft_push_back_tunnel(&data_store->tunnels, new_tunnel);
	return (1);
}
