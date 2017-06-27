/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_w_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:32:24 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:38:26 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_w_conv(t_datas *datas)
{
	va_list	cpy;
	int		fd;
	t_flags	flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit(datas));
	if (datas->un_ord == 1)
	{
		va_copy(cpy, datas->ap);
		while (flags.dollar-- > 0)
			va_arg(cpy, void *);
		fd = va_arg(cpy, int);
		va_end(cpy);
	}
	else
		fd = va_arg(datas->ap, int);
	datas->fd = fd;
	return (datas->result);
}
