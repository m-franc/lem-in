/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:39:15 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 16:35:52 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_line_is_tunnel(char *line, t_data_store *data_store)
{
	int		ti;
	int		other_ti;
	char	*f_room;
	char	*s_room;

	if (strcmp(line, "-") == 0)
		return (0);
	ti = strcspn(line, "-");
	f_room = ft_strsub(line, 0, ti);
	if (f_room[0] == 76 || f_room[0] == 35 || (line[ft_strlen(f_room)] != '-')
			|| ft_strlen(f_room) == 0)
	{
		ft_strdel(&f_room);	
		return (0);
	}
	other_ti = strcspn(line + (ti + 1), "-");
	s_room = ft_strsub(line, ti + 1, other_ti);
	if ((s_room[0] == 76 || s_room[0] == 35) || line[ti + other_ti + 1] != '\0'
			|| ft_strlen(s_room) == 0)
	{
		ft_strdel(&s_room);
		return (0);
	}
	return (ft_store_tunnel(data_store, f_room, s_room));
}

int			ft_line_is_ants_number(char *line, t_data_store *data_store)
{
	if (ft_str_isdigit(line))
	{
		if (ft_atoi(line) > 2147483647 || ft_atoi(line) < 1)
			return (-1);
		else
			return (ft_store_ants_number(data_store, line));
	}
	else
		return (0);
}

int			ft_line_is_room(char *line, t_data_store *data_store)
{
	char	**tab;
	
	tab = ft_strsplit(line, ' ');
	if (ft_tablen(tab) != 3
			|| (tab[0][0] == 76 || tab[0][0] == 35)
			|| ft_strchr(tab[0], '-')
			|| !ft_str_isdigit(tab[1])
			|| !ft_str_isdigit(tab[2]))
	{
		ft_tabdel(&tab);
		return (0);
	}
	if (ft_atoi(tab[1]) > 2147483647 || ft_atoi(tab[2]) > 2147483647)
	{
		ft_tabdel(&tab);
		return (0);	
	}
	return (ft_store_room(data_store, tab));
}

int			ft_line_is_comment(char *line, t_data_store *data_store)
{
	char	*comment_att;

	(void)data_store;
	if (!(comment_att = ft_strnstr(line, "#", 1)))
		return (0);
	else
	{
		ft_putendl("Its comment");
		return (1);
	}
}

int			ft_line_is_modif_command(char *line, t_data_store *data_store)
{
	char	*modif_att;

	if (!(modif_att = ft_strnstr(line, "##", 2)) || strnstr(line, "###", 3))
		return (0);
	else
	{
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##START") == 0)
		{
			if (data_store->start_mark > 1)
				return (-1);
			if (data_store->start_mark == 0)
				data_store->start_mark++;
		}
		else if (ft_strcmp(line, "##end") == 0 || ft_strcmp(line, "##END") == 0)
		{
			if (data_store->end_mark > 1)
				return (-1);
			if (data_store->end_mark == 0)
				data_store->end_mark++;	
		}
//		else
//			return (0);
		ft_putendl("Its command");
		return (1);
	}
}
