/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lx_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:30:02 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_lx_flags[] =
{
	ft_x_precision, ft_x_zero, ft_lx_diese, ft_d_padding,
};

static char				*ft_get_long_lx(t_datas *datas, t_flags *flags)
{
	char				*argcvd;
	unsigned long int	arg;

	if (datas->un_ord == 1)
		arg = ft_n_lu(datas, flags);
	else
		arg = va_arg(datas->ap, unsigned long int);
	if (!(argcvd = ft_uitoa(arg, 16, BASEUP)))
		return (NULL);
	return (argcvd);
}

static char				*ft_get_lx(t_datas *datas, t_flags *flags)
{
	char				*argcvd;
	unsigned int		arg;

	if (datas->un_ord == 1)
		arg = ft_n_u(datas, flags);
	else
		arg = va_arg(datas->ap, unsigned int);
	if (ft_strstr(datas->flags, "hh"))
		arg = (unsigned char)arg;
	else if (ft_strchr(datas->flags, 'h'))
		arg = (unsigned short)arg;
	if (!(argcvd = ft_uitoa(arg, 16, BASEUP)))
		return (NULL);
	return (argcvd);
}

static char				*ft_launch_lx_flags(t_datas *datas)
{
	char				*argcvd;
	int					nb_flags;
	t_flags				flags;

	argcvd = NULL;
	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit(datas));
	nb_flags = 0;
	if (ft_strchr(datas->flags, 'z') || ft_strchr(datas->flags, 'j')
			|| ft_strchr(datas->flags, 'l'))
	{
		if (!(argcvd = ft_get_long_lx(datas, &flags)))
			return (ft_exit_conv(datas, argcvd));
	}
	else
	{
		if (!(argcvd = ft_get_lx(datas, &flags)))
			return (ft_exit_conv(datas, argcvd));
	}
	while (nb_flags < 4)
	{
		if ((g_lx_flags[nb_flags++](&argcvd, &flags)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	return (argcvd);
}

char					*ft_get_lx_conv(t_datas *datas)
{
	char				*argcvd;

	if (!(argcvd = ft_launch_lx_flags(datas)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
