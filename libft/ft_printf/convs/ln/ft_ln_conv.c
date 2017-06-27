/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:27 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/27 16:07:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**ft_ln_n(t_datas *datas, t_flags *flags)
{
	va_list	copy;
	char	**arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, char **);
	va_end(copy);
	return (arg);
}

char		*ft_get_ln_conv(t_datas *datas)
{
	char	**cp_format;
	t_flags	flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		ft_exit(datas);
	if (datas->un_ord == 1)
	{
		if (!(cp_format = ft_ln_n(datas, &flags)))
			return (datas->result);
	}
	else
	{
		if (!(cp_format = va_arg(datas->ap, char **)))
			return (datas->result);
	}
	datas->cp_result = cp_format;
	*datas->cp_result = datas->result;
	datas->len = 0;
	return (datas->result);
}
