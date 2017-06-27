/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:27 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:31:53 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	*ft_n_n(t_datas *datas, t_flags *flags)
{
	va_list	copy;
	int		*arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, void*);
	va_end(copy);
	return (arg);
}

char		*ft_get_n_conv(t_datas *datas)
{
	int		*cp_len;
	t_flags	flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		ft_exit(datas);
	if (datas->un_ord == 1)
	{
		if (!(cp_len = ft_n_n(datas, &flags)))
			return (datas->result);
	}
	else
	{
		if (!(cp_len = va_arg(datas->ap, void*)))
			return (datas->result);
	}
	datas->tmp_len = cp_len;
	*datas->tmp_len = datas->len;
	return (datas->result);
}
