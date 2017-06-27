/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lu_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:27:49 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:28:59 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_lu_flags[] =
{
	ft_d_precision, ft_o_zero, ft_d_padding,
};

unsigned long int		ft_n_lu(t_datas *datas, t_flags *flags)
{
	va_list				copy;
	unsigned long int	arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, unsigned long int);
	va_end(copy);
	return (arg);
}

static char				*ft_launch_lu_flags(t_datas *datas)
{
	char				*argcvd;
	int					nb_flags;
	unsigned long int	arg;
	t_flags				flags;

	argcvd = NULL;
	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit(datas));
	nb_flags = 0;
	if (datas->un_ord == 1)
		arg = ft_n_lu(datas, &flags);
	else
		arg = va_arg(datas->ap, unsigned long int);
	if (!(argcvd = ft_uitoa(arg, 10, BASEUP)))
		return (ft_exit(datas));
	while (nb_flags < 3)
	{
		if ((g_lu_flags[nb_flags++](&argcvd, &flags)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	return (argcvd);
}

char					*ft_get_lu_conv(t_datas *datas)
{
	char				*argcvd;

	if (!(argcvd = ft_launch_lu_flags(datas)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
