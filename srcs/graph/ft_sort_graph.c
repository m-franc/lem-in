/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:32:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/16 18:47:03 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_get_index_start(t_datas_graph *datas_graph)
{
	t_adj_list	**tmp_list;
	int		i;

	tmp_list = datas_graph->adj_list;
	i = 0;
	while (i < datas_graph->nb_rooms && !tmp_list[i]->start)
		i++;
	if (i == datas_graph->nb_rooms)
		return (-1);
	return (i);
}

int			ft_get_index_end(t_datas_graph *datas_graph)
{
	t_adj_list	**tmp_list;
	int		i;

	tmp_list = datas_graph->adj_list;
	i = 0;
	while (i < datas_graph->nb_rooms && !tmp_list[i]->end)
		i++;
	if (i == datas_graph->nb_rooms)
		return (-1);
	return (i);
}

void			ft_put_start_top(t_adj_list **adj_list, int index_start, int index_top)
{
	t_adj_list	*tmp_top;
	int			id_top;
	
	tmp_top = adj_list[index_top];
	id_top = tmp_top->id;
	adj_list[index_top]->id = adj_list[index_start]->id;
	adj_list[index_top] = adj_list[index_start];
	adj_list[index_start]->id = id_top;
	adj_list[index_start] = tmp_top;
}

void			ft_put_end_bottom(t_adj_list **adj_list, int index_end, int index_bottom)
{
	t_adj_list	*tmp_bottom;
	int			id_bottom;
	
	tmp_bottom = adj_list[index_bottom];
	id_bottom = tmp_bottom->id;
	adj_list[index_bottom]->id = adj_list[index_end]->id;
	adj_list[index_bottom] = adj_list[index_end];
	adj_list[index_end]->id = id_bottom;
	adj_list[index_end] = tmp_bottom;
}

int			ft_sort_graph(t_datas_graph *datas_graph)
{
	int		index_start;
	int		index_end;
	
	if ((index_start = ft_get_index_start(datas_graph)) == -1)
		return (-1);
	if ((index_end = ft_get_index_end(datas_graph)) == -1)
		return (-1);
	if (index_start != 0)
		ft_put_start_top(datas_graph->adj_list, index_start, 0);
	if (index_end != (datas_graph->nb_rooms - 1))
		ft_put_end_bottom(datas_graph->adj_list, index_end, (datas_graph->nb_rooms - 1));
	return (1);
}

void			ft_sort_link_graph(t_adj_list **rooms, int size)
{
	t_ajd_list	**links;
	t_ajd_list	*tmp_link;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (++i < size)
	{
		links = rooms[i]->rooms_linked;
		while (++j < rooms[i]->nb_tunnels)
		{
			while (links[j]->dist > links[j + 1]->dist)
			{
				tmp_link = links[j];
				links[j] = links[j + 1];
				links[j + 1] = tmp_link;
				j = -1;
			}
		}
	}
}













