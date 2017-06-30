/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:58:51 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 15:26:37 by mfranc           ###   ########.fr       */
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
	int		line_is_command;

	while ((gnl = get_next_line(0, &line)))
	{
		i = -1;
		while (++i < 5)
		{
			line_is_command = g_line_is_command[i](line, data_store);
			if (line_is_command == 1)
				break ;
			else if (line_is_command == -1)
				return (-1);
		}
		if (i == 5)
			break ;
	}
	if (gnl == -1)
		return (-1);
	return (1);
}
