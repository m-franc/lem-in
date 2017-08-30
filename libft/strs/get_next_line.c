/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/08/30 17:37:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_file				*lstnew(t_file **begin, int fd)
{
	t_file			*new;

	if (!*begin)
	{
		if (!(*begin = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		(*begin)->fd = fd;
		if (!((*begin)->tmp = ft_strnew(0)))
			return (NULL);
		(*begin)->next = NULL;
		return (*begin);
	}
	else
	{
		if (!(new = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		new->fd = fd;
		if (!(new->tmp = ft_strnew(0)))
			return (NULL);
		new->next = *begin;
		*begin = new;
		return (new);
	}
}

t_file				*get_file(t_file **begin, int fd)
{
	t_file			*tmplst;
	t_file			*tmpnext;

	if (!*begin)
		return (*begin = lstnew(begin, fd));
	if ((*begin)->fd == fd)
		return (*begin);
	tmplst = *begin;
	tmpnext = (*begin)->next;
	while (tmpnext)
	{
		if (tmpnext->fd == fd)
		{
			tmplst->next = tmpnext->next;
			tmpnext->next = *begin;
			*begin = tmpnext;
			return (*begin);
		}
		tmplst = tmplst->next;
		tmpnext = tmpnext->next;
	}
	return (lstnew(begin, fd));
}

void				remove_file(t_file **file)
{
	t_file	*supp;

	supp = *file;
	ft_strdel(&(*file)->tmp);
	if ((*file)->next)
		*file = (*file)->next;
	else
		*file = NULL;
	ft_memdel((void**)&supp);
}

int					save_lines(char *ndtmp, t_file **file, char **line)
{
	char			*nexttmp;

	if ((*file)->tmp[0] == '\0')
	{
		remove_file(file);
		return (0);
	}
	if (ndtmp == NULL)
	{
		if (!(*line = ft_strdup((*file)->tmp)))
			return (-1);
		ft_bzero((*file)->tmp, ft_strlen((*file)->tmp));
		return (1);
	}
	else
	{
		if (!(*line = ft_strsub((*file)->tmp, 0, ft_strlen((*file)->tmp)
				- ft_strlen(ndtmp))))
			return (-1);
		nexttmp = (*file)->tmp;
		if (!((*file)->tmp = ft_strdup(ndtmp + 1)))
			return (-1);
		ft_strdel(&nexttmp);
		return (1);
	}
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmpline;
	char			*ndtmp;
	static t_file	*file;

	if (!line || (!(file = get_file(&file, fd))))
		return (-1);
	*line = NULL;
	ndtmp = ft_strchr(file->tmp, '\n');
	while (!ndtmp)
	{
		if ((ret = read(file->fd, buf, BUFF_SIZE)) == 0)
			break ;
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmpline = file->tmp;
		if (!(file->tmp = ft_strjoin(tmpline, buf)))
			return (-1);
		ft_strdel(&tmpline);
		ndtmp = ft_strchr(file->tmp, '\n');
	}
	return (save_lines(ndtmp, &file, line));
}
