/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:32:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/07 12:44:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct			s_data_rooms
{
	int					id;
	char				*name;
	int					tunnels;
	t_list				*rooms_linked;
	int					start;
	int					end;
	int					x;
	int					y;
	struct s_data_rooms	*next;
}						t_data_rooms;

typedef struct			s_tunnels
{
	char				*first_room;
	char				*second_room;
	int					checked;
	struct s_tunnels	*next;
}						t_tunnels;

typedef struct			s_data_store
{
	int					nb_ants;
	int					start_mark;
	int					end_mark;
	t_data_rooms		*rooms;
	t_data_rooms		*last_rooms;
	int					nb_rooms;
	t_tunnels			*tunnels;
	t_tunnels			*last_tunnels;
	int					nb_tunnels;
	t_list				*commands;
	t_list				*last_commands;
	int					nb_commands;
	int					gnl_error;
}						t_data_store;

typedef struct			s_adj_list
{
	int					id;
	char				*name;
	int					ant_in;
	int					dist;
	int					x;
	int					y;
	int					start;
	int					end;
	int					way_id;
	int					way_start;
	int					nb_tunnels;
	struct s_adj_list	**rooms_linked;
}						t_adj_list;

typedef struct			s_ants
{
	int					ant_number;
	t_adj_list			*curr_room;
	t_adj_list			*prev_room;
	int					way_id;
	int					comed;
	struct s_ants		*next;
	struct s_ants		*prev;
}						t_ants;

typedef struct			s_datas_graph
{
	int					nb_rooms;
	int					nb_links;
	int					nb_ways;
	t_adj_list			*adj_list;
	int					nb_ants;
	t_ants				*ants;
	t_ants				*last_ant;
}						t_datas_graph;

/*
 ** ft_display.c
*/
void					ft_put_data_tunnel(t_tunnels *tunnels);
void					ft_put_data_room(t_data_rooms *rooms);
void					ft_put_data_parsed(t_data_store *data_store);
void					ft_put_adj_list_elem(t_adj_list *list, int o);
void					ft_put_adj_list(t_datas_graph *datas_graph);

/*
 ** main.c
*/
void					ft_graph_building_and_setting(t_data_store *data_store,
		t_datas_graph **datas_graph);
void					ft_parse_and_store(t_data_store **data_store);
void					ft_anthill_part(t_list *commands,
		t_datas_graph *datas_graph);
void					lem_in(void);
void					ft_put_ants(t_ants *ants);

/*
 ** ft_exit.c
*/
int						ft_exit_function(int return_value, void *st_elem,
		void *nd_elem, void *rd_elem);
void					ft_exit_error(t_data_store *data_store,
		t_datas_graph *datas_graph);

/*
 ** ft_del_datas_graph.c
*/
void					ft_del_datas_graph(t_datas_graph *datas_graph);
void					ft_del_ants(t_ants *ants);
void					ft_del_adj_list(t_datas_graph *datas_graph);
void					ft_del_datas_graph(t_datas_graph *datas_graph);

/*
 ** ft_del_data_store.c
*/
void					ft_del_rooms(t_data_rooms *rooms);
void					ft_del_tunnels(t_tunnels *tunnels);
void					ft_del_data_store(t_data_store *data_store);
/*
 ** ft_is_parse_file.c
*/
t_data_store			*ft_data_store_init(void);
t_list					*ft_new_command(t_data_store *data_store, char *line);
int						ft_line_is_command(t_data_store *data_store,
		char *line);
int						ft_parse_file(t_data_store *data_store);

/*
 ** ft_is_comand.c
*/
int						ft_line_is_tunnel(char *line, t_data_store *data_store);
int						ft_line_is_room(char *line, t_data_store *data_store);
int						ft_line_is_ants_number(char *line,
		t_data_store *data_store);
int						ft_line_is_modif_command(char *line,
		t_data_store *data_store);
int						ft_line_is_comment(char *line,
		t_data_store *data_store);
typedef int				(*t_line_is_command)(char *line,
		t_data_store *data_store);

/*
 ** ft_store_command.c
*/
int						ft_store_tunnel(t_data_store *data_store,
		char *first_room, char *second_room);
int						ft_store_ants_number(t_data_store *data_store,
		char *line);
int						ft_store_room(t_data_store *data_store,
		char **data_room);
int						ft_store_modif_command(t_data_store *data_store,
		char *line);

/*
 ** ft_push.c
*/
void					ft_push_back_tunnel(t_data_store *data_store,
		t_tunnels *new_tunnel);
void					ft_push_back_room(t_data_store *data_store,
		t_data_rooms *new_room);
void					ft_push_back_command(t_data_store *data_store,
		t_list *new_command);

/*
 ** ft_check.c
*/
int						ft_check_duplicate(t_data_rooms *last_rooms,
		char **data_room);
int						ft_str_is_room(char *room);
int						ft_check_data_room(char **tab);

/*
 ** ft_build_graph.c
*/
t_datas_graph			*ft_init_datas_graph(t_data_store *data_store);
int						ft_build_graph(t_data_store *data_store,
		t_datas_graph *datas_graph);

/*
 ** ft_graph_sitting.c
*/
void					ft_update_rooms_id(t_datas_graph *datas_graph);

/*
 ** ft_build_adj_list.c
*/
int						ft_build_adj_list(t_data_store *data_store,
		t_datas_graph *datas_graph);
int						ft_init_elem_list_adj(t_adj_list *elem_list,
		t_data_rooms *tmp_rooms, int id, int nb_tunnels);
t_adj_list				*ft_get_room_by_name(char *room_to_find,
		t_datas_graph *datas_graph);
t_adj_list				*ft_get_room_by_tunnels(t_tunnels *rooms_to_find,
		t_datas_graph *datas_graph, char *current_room);
t_adj_list				**ft_init_rooms_linked(t_tunnels *tmp_tunnels,
		t_datas_graph *datas_graph, int nb_tunnels, char *current_room);

/*
 ** ft_build_adj_list.c
*/
t_adj_list				*ft_get_room_by_name(char *room_to_find,
		t_datas_graph *datas_graph);
t_adj_list				*ft_get_room_by_tunnels(t_tunnels *rooms_to_find,
		t_datas_graph *datas_graph, char *current_room);
int						ft_get_nb_tunnels(t_tunnels *tmp_tunnels,
		char *current_room);
int						ft_build_tunnels_adj_list(t_tunnels *tunnels,
		t_datas_graph *datas_graph);

/*
 ** ft_sort_graph.c
*/
int						ft_get_index_end(t_datas_graph *datas_graph);
int						ft_get_index_start(t_datas_graph *datas_graph);
int						ft_sort_graph(t_datas_graph *datas_graph);
void					ft_put_end_bottom(t_adj_list *adj_list,
		int index_end, int index_bottom);
void					ft_put_start_top(t_adj_list *adj_list,
		int index_start, int index_top);
void					ft_sort_link_graph(t_adj_list *rooms,
		int size);

/*
 ** ft_croos_map.c
*/
void					ft_init_dist(t_adj_list *current_room, int dist);
void					ft_move_ant_room(t_adj_list *curr_room,
		t_adj_list *next_room, t_ants *ant);
t_adj_list				*ft_get_next_room_way(t_adj_list *curr_room,
		t_adj_list *prev_room, int way_id);
void					ft_move_ants_map(t_datas_graph *datas_graph);
void					ft_map_crosser(t_datas_graph *datas_graph);

/*
 ** ft_init_ants.c
*/
void					ft_push_back_ants(t_datas_graph *datas_graph,
		t_ants *new_ant);
t_ants					*ft_new_ant(int ant_number, t_adj_list *start_room);
int						ft_init_ants(t_datas_graph *datas_graph);
int						ft_init_way_ants(t_ants **ants, int *way_id,
		int *starts_ways_index, t_datas_graph *datas_graph);
void					ft_init_ways_ants(t_datas_graph *datas_graph);

/*
 ** ft_init_ways.c
*/
void					ft_sort_link_room(t_adj_list *room);
int						ft_get_index_next_room(t_adj_list *curr_room);
int						ft_init_way(t_adj_list *start_room_link, int way_id);
void					ft_init_ways(t_datas_graph *datas_graph);

/*
 ** ft_delete_ants.c
*/
void					ft_ant_at_bottom(t_datas_graph *datas_graph,
		t_ants **ant);
void					ft_ant_at_head(t_datas_graph *datas_graph,
		t_ants **ant, t_ants *tmp_ant);
void					ft_ant_somewhere_in(t_ants **ant, t_ants *tmp_ant);
void					ft_delete_ant(t_datas_graph *datas_graph,
		t_ants **ant);
void					ft_del_ants_comed(t_datas_graph *datas_graph);

#endif
