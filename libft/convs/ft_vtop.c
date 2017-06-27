/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:30:54 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 18:54:35 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_vtop(const void *value)
{
	unsigned long		addr;
	char				*hexa;
	char				*pfx;
	char				*complete;

	if (!value)
		return (NULL);
	if (!(pfx = ft_strnew(2)))
		return (NULL);
	addr = (unsigned long)value;
	if (!(hexa = ft_itoa(addr, 16, BASELW)))
		return (NULL);
	pfx[0] = '0';
	pfx[1] = 'x';
	complete = ft_strjoin(pfx, hexa);
	ft_strdel(&pfx);
	ft_strdel(&hexa);
	return (complete);
}
