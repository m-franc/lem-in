/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:32:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/29 18:02:44 by mfranc           ###   ########.fr       */
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
}						t_data_store;

t_data_store			*ft_data_store_init(void);
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

/*
 ** 
 */
void					ft_push_back_tunnel(t_tunnels **tunnels, t_tunnels *new_tunnel);

#endif
