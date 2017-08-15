/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:39:15 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/15 18:52:33 by mfranc           ###   ########.fr       */
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
	if (!(f_room = ft_strsub(line, 0, ti)))
		return (-1);
	if (!ft_str_is_room(f_room) || line[ft_strlen(f_room)] != '-')
		return (ft_exit_function(0, f_room, NULL, NULL));
	other_ti = strcspn(line + (ti + 1), "-");
	if (!(s_room = ft_strsub(line, ti + 1, other_ti)))
		return (ft_exit_function(0, f_room, NULL, NULL));
	if (!ft_str_is_room(s_room) || line[ti + other_ti + 1] != '\0')
		return (ft_exit_function(0, f_room, s_room, NULL));
	if (ft_store_tunnel(data_store, f_room, s_room) == -1)
		return (ft_exit_function(-1, f_room, s_room, NULL));
	else
		return (1);
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
	
	if (!(tab = ft_strsplit(line, ' ')))
		return (-1);
	if (!ft_check_data_room(tab))
	{
		ft_tabdel(&tab);
		return (0);
	}
	if ((ft_atoi(tab[1]) > 2147483647 || ft_atoi(tab[1]) < -2147483648)
		|| (ft_atoi(tab[2]) > 2147483647 || ft_atoi(tab[2]) < -2147483648))
		return (ft_exit_function(0, tab[0], tab[1], tab[2]));
	if (ft_store_room(data_store, tab) == -1)
		return (ft_exit_function(-1, tab[0], tab[1], tab[2]));
	else
		return (1);
}

int			ft_line_is_comment(char *line, t_data_store *data_store)
{
	char	*comment_att;

	(void)data_store;
	if (!(comment_att = ft_strnstr(line, "#", 1)))
		return (0);
	else
		return (1);
}

int			ft_line_is_modif_command(char *line, t_data_store *data_store)
{
	char	*modif_att;

	if (!(modif_att = ft_strnstr(line, "##", 2)) || ft_strnstr(line, "###", 3))
		return (0);
	else
		return (ft_store_modif_command(data_store, line));
}
