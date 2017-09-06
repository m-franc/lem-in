/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:37:29 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/06 19:47:53 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		ft_exit_gnl(t_file *file, char **line)
{
	if (*line)
		ft_strdel(line);
	if (file)
	{
		if (file->tmp)
			ft_strdel(&file->tmp);
		ft_memdel((void**)&file);
	}
	return (-1);
}
