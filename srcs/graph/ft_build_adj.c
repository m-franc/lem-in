#include "lem-in.h"

void	ft_build_adj_list(t_data_store *data_store, t_adj_list *adj_list)
{
	t_data_rooms	*tmp_rooms;
	int		i;

	tmp_rooms = data_store->rooms;
	i = 0;
	while (tmp_rooms)
	{
		adj_list[i].id = i;
		adj_list[i].name = tmp_rooms->name;
		adj_list[i].x = tmp_rooms->x;
		adj_list[i].y = tmp_rooms->y;
		if (tmp_rooms->start)
			adj_list[i].start = 1;
		else
			adj_list[i].start = 0;
		if (tmp_rooms->end)
			adj_list[i].end = 1;
		else
			adj_list[i].end = 0;
		adj_list[i].rooms_linked = NULL;
		tmp_rooms = tmp_rooms->next;
		i++;
	}
}
