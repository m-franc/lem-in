/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:39:15 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/28 21:11:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_line_is_tunnel(char *line)
{
	int		ti;
	int		other_ti;
	char	*f_room;
	char	*s_room;

	if (strcmp(line, "-") == 0)
		return (0);
	ti = strcspn(line, "-");
	f_room = ft_strsub(line, 0, ti);
	if (f_room[0] == 76 || f_room[0] == 35 || (line[ft_strlen(f_room)] != '-'))
	{
		ft_strdel(&f_room);	
		return (0);
	}
	ft_strdel(&f_room);
	other_ti = strcspn(line + (ti + 1), "-");
	s_room = ft_strsub(line, ti + 1, other_ti);
	if ((s_room[0] == 76 || s_room[0] == 35) || line[ti + other_ti + 1] != '\0')
	{
		ft_strdel(&s_room);
		return (0);
	}
	ft_strdel(&s_room);
	return (1);
}

int			ft_line_is_ants_number(char *line)
{
	if (ft_str_isdigit(line))
		return (1);
	else
		return (0);
}

int			ft_line_is_room(char *line)
{
	char	**tab;
	
	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3
			|| (tab[0][0] == 76 || tab[0][0] == 35)
			|| !ft_str_isdigit(tab[1])
			|| !ft_str_isdigit(tab[2]))
	{
		ft_tabdel(&tab);
		return (0);
	}
	return (1);
}

int			ft_line_is_comment(char *line)
{
	char	*comment_att;

	if (!(comment_att = ft_strnstr(line, "#", 1)))
		return (0);
	else
		return (1);
}

int			ft_line_is_modif_command(char *line)
{
	char	*modif_att;

	if (!(modif_att = ft_strnstr(line, "##", 2)) || strnstr(line, "###", 3))
		return (0);
	else
		return (1);
}
