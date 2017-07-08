#include "lem-in.h"

t_adj_list		*ft_init_elem_list_adj(t_data_rooms *tmp_rooms, int id)
{
	t_adj_list	*elem_list;

	elem_list = ft_memalloc(sizeof(t_adj_list));
	elem_list->id = id;
	elem_list->name = tmp_rooms->name;
	elem_list->x = tmp_rooms->x;
	elem_list->y = tmp_rooms->y;
	if (tmp_rooms->start)
		elem_list->start = 1;
	else
		elem_list->start = 0;
	if (tmp_rooms->end)
		elem_list->end = 1;
	else
		elem_list->end = 0;
	elem_list->rooms_linked = NULL;
	return (elem_list);
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
		list[i] = ft_init_elem_list_adj(tmp_rooms, i);
		tmp_rooms = tmp_rooms->next;
		i++;
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

t_adj_list		**ft_init_rooms_linked(t_data_rooms *rooms, t_adj_list **tmp_list)
{
	int		o;
	t_adj_list	**rooms_linked;

	o = 0;
	rooms_linked = ft_memalloc(sizeof(t_adj_list*) * (rooms->tunnels + 1));
	while (rooms->rooms_linked)
	{	
		rooms_linked[o] = ft_get_room_by_name(rooms->rooms_linked->content, tmp_list);
		rooms->rooms_linked = rooms->rooms_linked->next;
		o++;
	}
	rooms_linked[o] = NULL;
	return (rooms_linked);
}

void			ft_build_tunnels_adj_list(t_data_rooms *rooms, t_adj_list **adj_list)
{
	t_adj_list	**list;
	t_adj_list	**tmp_list;
	t_data_rooms	*tmp_rooms;
	int		i;

	list = adj_list;
	tmp_list = adj_list;
	tmp_rooms = rooms;
	i = -1;
	while (list[++i] && tmp_rooms)
	{
		if (rooms->tunnels > 0)
			list[i]->rooms_linked = ft_init_rooms_linked(tmp_rooms, tmp_list);
		tmp_rooms = tmp_rooms->next;
	}
}
