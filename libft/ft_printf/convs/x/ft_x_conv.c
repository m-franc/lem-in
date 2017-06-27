/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:28:37 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:41:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_x_flags[] =
{
	ft_x_precision,
	ft_x_zero,
	ft_x_diese,
	ft_d_padding,
};

static char				*ft_get_long_x(t_datas *datas, t_flags *flags)
{
	char				*argcvd;
	unsigned long int	arg;

	if (datas->un_ord == 1)
		arg = ft_n_lu(datas, flags);
	else
		arg = va_arg(datas->ap, unsigned long int);
	if (datas->pointer == 1)
	{
		flags->pointer = 1;
		flags->diese = 1;
	}
	if (!(argcvd = ft_uitoa(arg, 16, BASELW)))
		return (ft_exit(datas));
	return (argcvd);
}

static char				*ft_get_x(t_datas *datas, t_flags *flags)
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
	if (!(argcvd = ft_uitoa(arg, 16, BASELW)))
		return (ft_exit(datas));
	return (argcvd);
}

static char				*ft_launch_x_flags(t_datas *datas)
{
	char				*argcvd;
	int					nb_flags;
	t_flags				flags;

	argcvd = NULL;
	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit(datas));
	nb_flags = 0;
	if (ft_strchr(datas->flags, 'z') || ft_strchr(datas->flags, 'j')
			|| ft_strchr(datas->flags, 'l') || datas->pointer == 1)
	{
		if (!(argcvd = ft_get_long_x(datas, &flags)))
			return (NULL);
	}
	else
	{
		if (!(argcvd = ft_get_x(datas, &flags)))
			return (NULL);
	}
	while (nb_flags < 4)
	{
		if ((g_x_flags[nb_flags++](&argcvd, &flags)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	return (argcvd);
}

char					*ft_get_x_conv(t_datas *datas)
{
	char				*argcvd;

	if (!(argcvd = ft_launch_x_flags(datas)))
		return (NULL);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	if (datas->pointer == 1)
		datas->pointer = 0;
	return (datas->result);
}
