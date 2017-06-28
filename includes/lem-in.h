/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:32:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/28 12:19:14 by mfranc           ###   ########.fr       */
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
	t_ctl_data_rooms	*rooms;
	t_tunnels			*tunnels;
}						t_data_store;

t_data_store			*ft_data_store_init(void);
t_ctl_data_rooms		*ft_data_rooms_init(void);

#endif
