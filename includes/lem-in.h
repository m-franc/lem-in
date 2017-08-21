/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:32:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/21 15:12:32 by mfranc           ###   ########.fr       */
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
	int					nb_tunnels;
	struct s_adj_list	**rooms_linked;
}						t_adj_list;
/*
typedef struct			s_ways
{
	int					id;
	int					ended;
	int					nb_rooms;
	t_adj_list			*rooms;
	struct s_ways		*next;
	struct s_ways		*prev;
}						t_ways;
*/
typedef struct			s_ants
{
	int					ant_number;
	t_adj_list			*curr_room;
	int					way_id;
	int					comed;
	struct s_ants		*next;
	struct s_ants		*prev;
}						t_ants;

typedef struct 			s_datas_graph
{
	int					**adj_matrix;
	int					nb_rooms;
	int					nb_links;
	t_adj_list			**adj_list;
	int					nb_ants;
	t_ants				*ants;
	t_ants				*last_ant;
}						t_datas_graph;

/*
 ** ft_display.c
 */
void					ft_put_data_parsed(t_data_store *data_store);
void					ft_put_adj_list(t_datas_graph *datas_graph);
void					ft_put_adj_list_dist(t_datas_graph *datas_graph);
void					ft_put_adj_matrix(t_datas_graph *datas_graph);
//void					ft_put_ways(t_ways *ways);

/*
 ** main.c.c
 */
t_data_store			*ft_data_store_init(void);
void					ft_exit_error(void);
int						ft_exit_function(int return_value, void *st_elem, void *nd_elem, void *rd_elem);
int						ft_check_room_tunnel(t_data_store *data_store);

/*
 ** ft_is_parse_file.c
 */
int						ft_parse_file(t_data_store *data_store);

/*
 ** ft_is_comand.c
 */
int						ft_line_is_tunnel(char *line, t_data_store *data_store);
int						ft_line_is_room(char *line, t_data_store *data_store);
int						ft_line_is_ants_number(char *line, t_data_store *data_store);
int						ft_line_is_modif_command(char *line, t_data_store *data_store);
int						ft_line_is_comment(char *line, t_data_store *data_store);

typedef int				(*t_line_is_command)(char *line, t_data_store *data_store);

/*
 ** ft_store_command.c
 */
int						ft_store_tunnel(t_data_store *data_store, char *first_room, char *second_room);
int						ft_store_ants_number(t_data_store *data_store, char *line);
int						ft_store_room(t_data_store *data_store, char **data_room);
int						ft_store_modif_command(t_data_store *data_store, char *line);

/*
 ** ft_push.c 
 */
void					ft_push_back_tunnel(t_data_store *data_store, t_tunnels *new_tunnel);
void					ft_push_back_room(t_data_store *data_store, t_data_rooms *new_room);
void					ft_push_back_command(t_data_store *data_store, t_list *new_command);

/*
 ** ft_check.c
 */
int						ft_check_duplicate(t_data_rooms *last_rooms, char **data_room);
int						ft_str_is_room(char *room);
int						ft_check_data_room(char **tab);

/*
 ** ft_build_graph.c
 */
t_datas_graph			*ft_init_datas_graph(t_data_store *data_store);
void					ft_switchon_tunnels_adj_matrix(t_datas_graph *datas_graph);
int						ft_build_graph(t_data_store *data_store, t_datas_graph *datas_graph);

/*
 ** ft_graph_sitting.c
 */
void					ft_update_rooms_id(t_datas_graph *datas_graph);
int						ft_get_nb_new_tunnels(t_adj_list *list_elem, t_adj_list **og_list, int index_list);
void					ft_new_tunnels(t_adj_list *elem_list, int nb_new_tunnels, t_adj_list **og_list, int index_list);
int						ft_reorganize_tunnels_adj_list(t_datas_graph *datas_graph);

/*
 ** ft_build_adj_list.c
 */
int						ft_build_adj_list(t_data_store *data_store, t_datas_graph *datas_graph);
t_adj_list				*ft_init_elem_list_adj(t_data_rooms *tmp_rooms, int id, int nb_tunnels);
t_adj_list				*ft_get_room_by_name(char *room_to_find, t_datas_graph *datas_graph);
t_adj_list				*ft_get_room_by_tunnels(t_tunnels *rooms_to_find, t_datas_graph *datas_graph, char *current_room);
int						ft_get_nb_tunnels(t_tunnels *tmp_tunnels, char *current_room);
int						ft_build_tunnels_adj_list(t_tunnels *tunnels, t_datas_graph *datas_graph);
t_adj_list				**ft_init_rooms_linked(t_tunnels *tmp_tunnels, t_datas_graph *datas_graph, int nb_tunnels, char *current_room);

/*
 ** ft_sort_graph.c
 */
int						ft_get_index_end(t_datas_graph *datas_graph);
int						ft_get_index_start(t_datas_graph *datas_graph);
int						ft_sort_graph(t_datas_graph *datas_graph);
void					ft_put_end_bottom(t_adj_list **adj_list, int index_end, int index_bottom);
void					ft_put_start_top(t_adj_list **adj_list, int index_start, int index_top);
void					ft_sort_link_graph(t_adj_list **rooms, int size);

/*
 ** ft_build_ways.c
 */
void					ft_init_dist(t_adj_list *current_room, int dist);
void					ft_init_start_ways(t_datas_graph *datas_graph);
void					ft_sort_link_room(t_adj_list *room);
//t_adj_list				*ft_new_room_way(t_adj_list *content_elem_list);
//t_ways					*ft_new_way(t_adj_list *content_elem_list, int id);
//void					ft_push_back_ways(t_ways **ways, t_ways *new_way);
void					ft_map_crosser(t_datas_graph *datas_graph);

/*
 ** ft_init_next_rooms.c
 */
//void					ft_push_back_room_way(t_ways *ways, t_adj_list *next_room);
//t_adj_list				*ft_get_current_last_room_way(t_ways *way);
//t_ways					*ft_way_dup(t_ways *way_src);
//void					ft_push_back_after_nway(t_ways *og_ways, t_ways *new_way, int nway);
//void					ft_update_ways_id(t_ways *ways);
//int						ft_init_multiple_next_rooms(t_datas_graph *datas_graph, t_adj_list *last_room, t_adj_list **last_room_rooms_linked, t_ways *way);
//int						ft_init_next_rooms(t_datas_graph *datas_graph, t_adj_list *last_room, t_ways *way);
void					ft_init_second_room(t_datas_graph *datas_graph);

/*
 ** ft_init_ants.c
 */
t_ants					*ft_new_ant(int ant_number, t_adj_list *start_room);
int						ft_init_ants(t_datas_graph *datas_graph);

/*
 ** ft_init_ways.c
 */

void			ft_sort_link_room(t_adj_list *room);
int				ft_init_way(t_adj_list *start_room_link, int way_id);
void			ft_init_ways(t_datas_graph *datas_graph);

#endif
