/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:32:55 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_o_flags[] =
{
	ft_d_precision, ft_o_zero, ft_o_diese, ft_d_padding,
};

static unsigned int	ft_n_o(t_datas *datas, t_flags *flags)
{
	va_list			copy;
	unsigned int	arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, unsigned int);
	va_end(copy);
	return (arg);
}

static char			*ft_launch_o_flags(t_datas *datas)
{
	char			*argcvd;
	int				nb_flags;
	unsigned int	arg;
	t_flags			flags;

	argcvd = NULL;
	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit(datas));
	nb_flags = 0;
	if (datas->un_ord == 1)
		arg = ft_n_o(datas, &flags);
	else
		arg = va_arg(datas->ap, unsigned int);
	if (ft_strstr(datas->flags, "hh"))
		arg = (unsigned char)arg;
	else if (ft_strchr(datas->flags, 'h'))
		arg = (unsigned short)arg;
	if (!(argcvd = ft_uitoa(arg, 8, BASEUP)))
		return (ft_exit(datas));
	while (nb_flags < 4)
	{
		if ((g_o_flags[nb_flags++](&argcvd, &flags)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	return (argcvd);
}

char				*ft_get_o_conv(t_datas *datas)
{
	char			*argcvd;

	if (ft_strchr(datas->flags, 'l') || ft_strchr(datas->flags, 'j')
			|| ft_strchr(datas->flags, 'z'))
		return (ft_get_lo_conv(datas));
	else
	{
		if (!(argcvd = ft_launch_o_flags(datas)))
			return (NULL);
		if (!(datas->result = ft_strjoin(datas->result, argcvd)))
			return (ft_exit_conv(datas, argcvd));
		datas->len += ft_strlen(argcvd);
		ft_strdel(&argcvd);
		return (datas->result);
	}
}
