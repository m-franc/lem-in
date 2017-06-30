/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:32:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 19:23:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct			s_data_rooms
{
	char				*name;
	int					tunnels;
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
	struct s_tunnels	*next;
}						t_tunnels;

typedef struct			s_data_store
{
	int					nb_ants;
	int					start_mark;
	int					end_mark;
	t_data_rooms		*rooms;
	int					nb_rooms;
	t_tunnels			*tunnels;
	int					nb_tunnels;
	t_list				*commands;
}						t_data_store;



/*
 ** ft_display.c
 */
void					ft_put_data_parsed(t_data_store *data_store);

/*
 ** main.c.c
 */
t_data_store			*ft_data_store_init(void);
void					ft_exit_error(void);
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
void					ft_push_back_tunnel(t_tunnels **tunnels, t_tunnels *new_tunnel);
void					ft_push_back_room(t_data_rooms **rooms, t_data_rooms *new_room);
void					ft_push_back_command(t_list **commands, t_list *new_command);

/*
 ** ft_check.c
 */
int						ft_check_duplicate(t_data_rooms *last_rooms, char **data_room);
int						ft_str_is_room(char *room);
int						ft_check_data_room(char **tab);

#endif
