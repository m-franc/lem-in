/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:53:06 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 18:11:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wint_t wchar, int fd)
{
	char	*unicode;

	if (fd < 0)
		return ;
	if (!(unicode = ft_wctoa(wchar)))
		return ;
	ft_putstr_fd(unicode, fd);
	ft_strdel(&unicode);
}
