#include "lem-in.h"

int			ft_get_index_start(t_adj_list **adj_list)
{
	t_adj_list	**tmp_list;
	int		i;

	tmp_list = adj_list;
	i = 0;
	while (!tmp_list[i]->start)
		i++;
	return (i);
}

int			ft_get_index_end(t_adj_list **adj_list)
{
	t_adj_list	**tmp_list;
	int		i;

	tmp_list = adj_list;
	i = 0;
	while (!tmp_list[i]->end)
		i++;
	return (i);
}

void			ft_put_start_top(t_adj_list **adj_list, int index_start, int index_top)
{
	t_adj_list	*tmp_top;
	
	tmp_top = adj_list[index_top];
	adj_list[index_top] = adj_list[index_start];
	adj_list[index_start] = tmp_top;
}

void			ft_put_end_bottom(t_adj_list **adj_list, int index_end, int index_bottom)
{
	t_adj_list	*tmp_bottom;
	
	tmp_bottom = adj_list[index_bottom];
	adj_list[index_bottom] = adj_list[index_end];
	adj_list[index_end] = tmp_bottom;
}

void			ft_sort_graph(t_datas_graph *datas_graph)
{
	int		index_start;
	int		index_end;
	
	index_start = ft_get_index_start(datas_graph->adj_list);
	index_end = ft_get_index_end(datas_graph->adj_list);
	if (index_start != 0)
		ft_put_start_top(datas_graph->adj_list, index_start, 0);
	if (index_end != (datas_graph->nb_rooms - 1))
		ft_put_end_bottom(datas_graph->adj_list, index_end, (datas_graph->nb_rooms - 1));
}
