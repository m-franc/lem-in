/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:58:51 by mfranc            #+#    #+#             */
/*   Updated: 2017/06/30 18:02:37 by mfranc           ###   ########.fr       */
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

static void	ft_store_command(t_data_store *data_store, char *line)
{
	t_list	*last_commands;
	t_list	*new_command;

	new_command = ft_lstnew(line, ft_strlen(line));
	last_commands = data_store->commands;
	if (!last_commands)
		ft_push_back_command(&data_store->commands, new_command);
	else
		ft_push_back_command(&last_commands, new_command);
}

int			ft_parse_file(t_data_store *data_store)
{
	int		gnl;
	int		i;
	char	*line;
	int		line_is_command;

	while ((gnl = get_next_line(0, &line)) == 1)
	{
		i = -1;
		ft_store_command(data_store, line);
//		ft_putlist(data_store->commands);
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
		ft_put_data_parsed(data_store);
		ft_strdel(&line);
	}
	if (gnl == -1)
		return (-1);
	return (1);
}
