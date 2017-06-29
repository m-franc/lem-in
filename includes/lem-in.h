/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:32:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/29 11:11:45 by mfranc           ###   ########.fr       */
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
	struct s_data_rooms	*prev;
}						t_data_rooms;

typedef struct			s_ctl_data_rooms
{
	int					size;
	t_data_rooms		*first;
	t_data_rooms		*last;
}						t_ctl_data_rooms;

typedef struct			s_tunnels
{
	char				*from;
	char				*to;
	struct s_tunnels	*next;
}						t_tunnels;

typedef struct			s_data_store
{
	int					nb_ants;
	int					start_mark;
	int					end_mark;
	t_ctl_data_rooms	*rooms;
	t_tunnels			*tunnels;
}						t_data_store;

t_data_store			*ft_data_store_init(void);
t_ctl_data_rooms		*ft_data_rooms_init(void);
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

#endif
