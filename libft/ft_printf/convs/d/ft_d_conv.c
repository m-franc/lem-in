/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:18:42 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:09:48 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_d_flags[] =
{
	ft_d_precision, ft_d_zero, ft_d_plus, ft_d_space, ft_d_padding,
};

int			ft_n_d(t_datas *datas, t_flags *flags)
{
	va_list	copy;
	int		arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, int);
	va_end(copy);
	return (arg);
}

static char	*ft_launch_d_flags(t_datas *datas)
{
	char	*argcvd;
	int		nb_flags;
	int		arg;
	t_flags	flags;

	argcvd = NULL;
	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit_conv(datas, argcvd));
	nb_flags = 0;
	if (datas->un_ord == 1)
		arg = ft_n_d(datas, &flags);
	else
		arg = va_arg(datas->ap, int);
	if (ft_strstr(datas->flags, "hh"))
		arg = (char)arg;
	else if (ft_strchr(datas->flags, 'h'))
		arg = (short)arg;
	if (!(argcvd = ft_itoa(arg, 10, BASEUP)))
		return (ft_exit_conv(datas, argcvd));
	while (nb_flags < 5)
	{
		if ((g_d_flags[nb_flags++](&argcvd, &flags)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	return (argcvd);
}

char		*ft_get_d_conv(t_datas *datas)
{
	char	*argcvd;

	if (ft_strchr(datas->flags, 'l') || ft_strchr(datas->flags, 'j')
			|| ft_strchr(datas->flags, 'z'))
		return (ft_get_ld_conv(datas));
	else
	{
		if (!(argcvd = ft_launch_d_flags(datas)))
			return (ft_exit(datas));
		if (!(datas->result = ft_strjoin(datas->result, argcvd)))
			return (ft_exit_conv(datas, argcvd));
		datas->len += ft_strlen(argcvd);
		ft_strdel(&argcvd);
		return (datas->result);
	}
}
