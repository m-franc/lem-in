/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:50:13 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/04 18:25:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_ant_at_bottom(t_datas_graph *datas_graph, t_ants **ant)
{
	datas_graph->last_ant = (*ant)->prev;
	(*ant)->prev->next = NULL;
	*ant = NULL;
}

void			ft_ant_at_head(t_datas_graph *datas_graph,
		t_ants **ant, t_ants *tmp_ant)
{
	datas_graph->ants = tmp_ant->next;
	datas_graph->ants->prev = NULL;
	*ant = datas_graph->ants;
}

void			ft_ant_somewhere_in(t_ants **ant, t_ants *tmp_ant)
{
	(*ant)->prev->next = tmp_ant->next;
	(*ant)->next->prev = tmp_ant->prev;
	*ant = tmp_ant->next;
}

void			ft_delete_ant(t_datas_graph *datas_graph, t_ants **ant)
{
	t_ants		*tmp_ant;

	tmp_ant = *ant;
	if (datas_graph->nb_ants == 1)
	{
		datas_graph->ants = NULL;
		datas_graph->last_ant = NULL;
		*ant = NULL;
	}
	else if (!tmp_ant->prev)
		ft_ant_at_head(datas_graph, ant, tmp_ant);
	else if (!tmp_ant->next)
		ft_ant_at_bottom(datas_graph, ant);
	else
		ft_ant_somewhere_in(ant, tmp_ant);
	ft_bzero(tmp_ant, sizeof(t_ants));
	ft_memdel((void**)&tmp_ant);
	datas_graph->nb_ants--;
}

void			ft_del_ants_comed(t_datas_graph *datas_graph)
{
	t_ants		*ants;

	ants = datas_graph->ants;
	while (ants)
	{
		if (ants->curr_room->end)
			ft_delete_ant(datas_graph, &ants);
		else
			ants = ants->next;
	}
}
