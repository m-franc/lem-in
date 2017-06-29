/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:27:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/29 15:46:46 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_store_tunnel(t_data_store *data_store, char *first_room, char *second_room)
{
	t_tunnels	*new_tunnel;
	t_tunnels	*last_tunnels;
	
	if (!(new_tunnel = (t_tunnels*)malloc(sizeof(t_tunnels))))
		exit(-1);
	new_tunnel->first_room = first_room;
	new_tunnel->second_room = second_room;
	new_tunnel->next = NULL;
	last_tunnels = data_store->tunnels;
	if (!last_tunnels)
		ft_push_back_tunnel(&data_store->tunnels, new_tunnel);
	else
		ft_push_back_tunnel(&last_tunnels, new_tunnel);
	return (1);
}

int		ft_store_ants_number(t_data_store *data_store, char *ants_number)
{
	long long	nb_ants;

	nb_ants = ft_atoi(ants_number);
	if (nb_ants > 2147483647 || nb_ants < 1)
		return (0);
	data_store->nb_ants = nb_ants;
	ft_printf("{purple}%10d{eoc}", data_store->nb_ants);
	return (1);
}
