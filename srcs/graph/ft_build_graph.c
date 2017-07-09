#include "lem-in.h"

t_datas_graph		*ft_init_datas_graph(t_data_store *data_store)
{
	t_datas_graph	*datas_graph;
	int		**adj_matrix;
	t_adj_list	**adj_list;
	int		i;

	if (!(datas_graph = (t_datas_graph*)malloc(sizeof(t_datas_graph))))
		exit(1);
	i = -1;
	adj_matrix = ft_memalloc(sizeof(int*) * (data_store->nb_rooms + 1));
	while (++i < data_store->nb_rooms)
		adj_matrix[i] = ft_memalloc(sizeof(int) * data_store->nb_rooms);
	datas_graph->adj_matrix = adj_matrix;
	i = -1;
	adj_list = ft_memalloc(sizeof(t_adj_list*) * (data_store->nb_rooms + 1));
	datas_graph->adj_list = adj_list;
	datas_graph->nb_rooms = data_store->nb_rooms;
	return (datas_graph);
}

void			ft_build_graph(t_data_store *data_store, t_datas_graph *datas_graph)
{
	ft_build_adj_list(data_store, datas_graph->adj_list);
	ft_build_tunnels_adj_list(data_store->rooms, datas_graph->adj_list);
	ft_sort_graph(datas_graph);
	ft_switchon_tunnels_adj_matrix(datas_graph);
}
