/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:58:51 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/28 19:51:36 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_parse_file(t_data_store *data_store)
{
	int		gnl;
	char	*line;

	(void)data_store;
	while ((gnl = get_next_line(0, &line)))
	{
		ft_putstrcolor(line, BLUE);
		ENDL
		if (ft_line_is_ants_number(line))
			ft_putendl("ok its ants number");
		else if (ft_line_is_tunnel(line))
			ft_putendl("ok its tunnel");
		else if (ft_line_is_room(line))
			ft_putendl("ok its room");
		else if (ft_line_is_modif_command(line))
			ft_putendl("ok its modif command");
		else if (ft_line_is_comment(line))
			ft_putendl("ok its comment");
		else
		{
			ft_putendl("out !");
			break ;
		}
	}
	if (gnl == -1)
		return (-1);
	return (1);
}
