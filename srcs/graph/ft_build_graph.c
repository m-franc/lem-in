#include "lem-in.h"

t_datas_graph		*ft_init_datas_graph(t_data_store *data_store)
{
	t_datas_graph	*datas_graph;
	int		**adj_matrix;
	t_adj_list	**adj_list;
	//	t_adj_list	*list_elem;
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
	while (++i < data_store->nb_rooms)
		adj_list[i] = ft_memalloc(sizeof(t_adj_list));
	datas_graph->adj_list = adj_list;
	datas_graph->nb_rooms = data_store->nb_rooms;
	return (datas_graph);
}

void			ft_build_adj_list(t_data_store *data_store, t_adj_list **adj_list)
{
	t_data_rooms	*tmp_rooms;
	t_adj_list	**list;
	int		i;

	list = adj_list;
	tmp_rooms = data_store->rooms;
	i = 0;
	while (tmp_rooms)
	{
		list[i]->id = i;
		list[i]->name = tmp_rooms->name;
		list[i]->x = tmp_rooms->x;
		list[i]->y = tmp_rooms->y;
		if (tmp_rooms->start)
			list[i]->start = 1;
		else
			list[i]->start = 0;
		if (tmp_rooms->end)
			list[i]->end = 1;
		else
			list[i]->end = 0;
		list[i++]->rooms_linked = NULL;
		tmp_rooms = tmp_rooms->next;
	}
	list[i] = NULL;
}

t_adj_list		*ft_get_room_by_name(char *room_to_find, t_adj_list **list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		if (ft_strequ(list[i]->name, room_to_find))
			return (list[i]);
		i++;
	}
	return (NULL);
}

void			ft_init_rooms_linked(t_data_store *data_store, t_datas_graph *datas_graph)
{
	t_adj_list	**list;
	t_adj_list	**tmp_list;
	t_data_rooms	*rooms;
	int		i;
	int		o;

	list = datas_graph->adj_list;
	tmp_list = datas_graph->adj_list;
	rooms = data_store->rooms;
	i = -1;
	while (list[++i])
	{
		o = 0;
		if (rooms->tunnels > 0)
		{
			list[i]->rooms_linked = ft_memalloc(sizeof(t_adj_list*) * (rooms->tunnels + 1));
			while (rooms->rooms_linked)
			{	
				list[i]->rooms_linked[o] = ft_get_room_by_name(rooms->rooms_linked->content, tmp_list);
				rooms->rooms_linked = rooms->rooms_linked->next;
				o++;
			}
			list[i]->rooms_linked[o] = NULL;
		}
		rooms = rooms->next;
	}
}
