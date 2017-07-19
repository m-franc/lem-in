



int				ft_init_multiple_next_rooms(t_datas_graph *datas_graph, t_adj_list *last_room, t_adj_list **last_room_rooms_linked, t_ways *way)	
{
	int			o;
	int			u;
	t_ways		*new_way;
	t_ways		*tmp_way;
	t_adj_list	*new_room;
	t_adj_list	*prev_way_current_room;

	o = 0;
	u = 0;
	tmp_way = ft_way_dup(way);
//	PSTR("-----------")
//	ft_put_ways(way);
//	PSTR(last_room->name)
//	PNBR(last_room->nb_tunnels)
//	sleep(1);
	prev_way_current_room = ft_get_same_room(way->prev, last_room->name);
	while (o < first_room->nb_tunnels)
	{
		if (!ft_get_antecedant(last_room_rooms_linked[o], way))
		{
			if (prev_way_current_room)
			{
				if (prev_way_current_room->next)
				{
			//		ft_put_ways(way->prev);
			//		PSTR("===")
		//			PSTR("//////////////////////////////////////////////////")
					if (!ft_strequ(prev_way_current_room->next->name, last_room_rooms_linked[o]->name))
					{
					//	ft_printf("{blue}%s{eoc}\n", prev_way_current_room->name);
						
						new_room = ft_new_room_way(last_room_rooms_linked[o]);
						ft_push_back_room_way(way, new_room);
						if (o == (last_room->nb_tunnels - 1))
							break ;
						new_way = ft_way_dup(tmp_way);
						ft_push_back_after_nway(datas_graph->ways, new_way, way->id);
						ft_update_ways_id(datas_graph->ways);
						way = new_way;
					}
					else
						return (0);
				}
				else
				{
					new_room = ft_new_room_way(last_room_rooms_linked[o]);
					ft_push_back_room_way(way, new_room);
					if (o == (last_room->nb_tunnels - 1))
						break ;
					new_way = ft_way_dup(tmp_way);
					ft_push_back_after_nway(datas_graph->ways, new_way, way->id);
					ft_update_ways_id(datas_graph->ways);
					way = new_way;
				}
			}					
			else
			{	
				new_room = ft_new_room_way(last_room_rooms_linked[o]);
				ft_push_back_room_way(way, new_room);
				if (o == (last_room->nb_tunnels - 1))
					break ;
				new_way = ft_way_dup(tmp_way);
				ft_push_back_after_nway(datas_graph->ways, new_way, way->id);
				ft_update_ways_id(datas_graph->ways);
				way = new_way;
			}
		}
		else
			u++;
		o++;
	}
	if (u == last_room->nb_tunnels)
		return (0);
	else
		return (1);
}

