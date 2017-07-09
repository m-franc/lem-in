#include "lem-in.h"

void	ft_switchon_tunnels_adj_matrix(t_datas_graph *datas_graph)
{
	int		**matrix;
	t_adj_list	**list;
	t_adj_list	**rooms_linked;
	int		i;
	int		o;

	matrix = datas_graph->adj_matrix;
	list = datas_graph->adj_list;
	i = 0;
	while (i < datas_graph->nb_rooms)
	{
		rooms_linked = list[i]->rooms_linked;
		o = 0;
		while (rooms_linked[o])
		{
			matrix[i][rooms_linked[o]->id] = 1;
			o++;
		}
		i++;
	}
}
