/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:14:02 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/16 21:26:41 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_ants			*ft_new_ant(int ant_number)
{
	t_ants		*ant;

	if (!(ant = ft_memalloc(sizeof(t_ants))))
		return (NULL);
	ant->ant_number = ant_number;
	ant->curr_room = NULL;
	ant->comed = 0;
	return (ant);
}

int				ft_init_ants(t_datas_graph *datas_graph)
{
	int			ant_number;
	int			i;
	
	if (!(ants = ft_memalloc(sizeof(t_ants*) * nb_ants)))
		return (-1);
	i = -1;
	ant_number = 1;
	datas_graph->ants = ants;
	while (++i < nb_ants)
	{
		if (!(ants[i] = ft_new_ant(ant_number)))
			return (-1);
		ant_number++;
	}
	return (1);
}

