/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:58:51 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/28 16:48:57 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_line_is_tunnel(char *line)
{
	int		i;

	i = 0;
	while (line[i] >= 0 && line[i] <= 127 && line[i] != 76 && line[i] != 35)
		i++;
	if (line[i] != '-')
		return (0);
	else if (line[i] == 76 || line[i] == 35)
		return (0);
	i++;
	while (line[i] >= 0 && line[i] <= 127 && line[i] != 127 && line[i] != 35)
		i++;
	if (line[i] == 76 || line[i] == 35)
		return (0);
	return (1);
}

int			ft_line_is_room(char *line)
{

	return (1);
}

int			ft_parse_file(t_data_store *data_store)
{
	int		gnl;
	char	*line;

	while ((gnl = get_next_line(0, &line)))
	{

	}
	if (gnl == -1)
		return (-1);
	return (1);
}
