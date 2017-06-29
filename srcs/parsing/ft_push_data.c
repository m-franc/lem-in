/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 11:31:34 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/29 15:09:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_push_back_tunnel(t_tunnels **tunnels, t_tunnels *new_tunnel)
{
	t_tunnels	*tmp;

	if (!*tunnels)
	{	
		*tunnels = new_tunnel;
		return ;
	}
	else
	{
		tmp = *tunnels;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new_tunnel;
	}
}
