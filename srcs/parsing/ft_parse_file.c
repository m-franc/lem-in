/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:58:51 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/29 17:54:45 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_line_is_command	g_line_is_command[] = 
{
	ft_line_is_ants_number,
	ft_line_is_room,
	ft_line_is_tunnel,
	ft_line_is_modif_command,
	ft_line_is_comment
};

int			ft_parse_file(t_data_store *data_store)
{
	int		gnl;
	int		i;
	char	*line;

	while ((gnl = get_next_line(0, &line)))
	{
		i = -1;
		while (++i < 5)
		{
			if (g_line_is_command[i](line, data_store))
				break ;
		}
		if (i == 5)
			break ;
	}
	if (gnl == -1)
		return (-1);
	return (1);
}
