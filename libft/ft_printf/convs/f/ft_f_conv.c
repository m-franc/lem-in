/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:18:42 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 17:27:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_f_flags[] =
{
	ft_f_zero, ft_d_padding,
};

static double	ft_n_f(t_datas *datas, t_flags *flags)
{
	va_list		copy;
	double		arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, double);
	va_end(copy);
	return (arg);
}

static char		*ft_launch_f_flags(t_datas *datas)
{
	char		*argcvd;
	int			nb_flags;
	double		arg;
	t_flags		flags;

	argcvd = NULL;
	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit_conv(datas, argcvd));
	nb_flags = 0;
	if (datas->un_ord == 1)
		arg = ft_n_f(datas, &flags);
	else
		arg = va_arg(datas->ap, double);
	if (flags.precision == -1)
		flags.precision = 6;
	if (!(argcvd = ft_ftoa(arg, flags.precision)))
		return (ft_exit_conv(datas, argcvd));
	while (nb_flags < 2)
	{
		if ((g_f_flags[nb_flags++](&argcvd, &flags)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	return (argcvd);
}

char			*ft_get_f_conv(t_datas *datas)
{
	char		*argcvd;

	if (!(argcvd = ft_launch_f_flags(datas)))
		return (ft_exit(datas));
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
