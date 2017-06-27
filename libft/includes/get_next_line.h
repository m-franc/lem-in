/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 20:23:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/09 15:50:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 100

typedef struct			s_file
{
	char				*tmp;
	int					fd;
	struct s_file		*next;
}						t_file;

int						get_next_line(const int fd, char **line);
int						save_lines(char *ndtmp, t_file **file, char **line);
void					remove_file(t_file **file);
t_file					*get_file(t_file **file, int fd);
t_file					*lstnew(t_file **begin, int fd);

#endif
