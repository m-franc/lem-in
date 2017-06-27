/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:44:41 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 18:12:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwendl_fd(wchar_t *str, int fd)
{
	char	*unicode;

	if (fd < 0)
		return ;
	if (!(unicode = ft_wstrtoa(str)))
		return ;
	ft_putendl_fd(unicode, fd);
	ft_strdel(&unicode);
}
