/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:43:22 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 18:11:56 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr_fd(wchar_t *str, int fd)
{
	char	*unicode;

	if (fd < 0)
		return ;
	if (!(unicode = ft_wstrtoa(str)))
		return ;
	ft_putstr_fd(unicode, fd);
	ft_strdel(&unicode);
}
