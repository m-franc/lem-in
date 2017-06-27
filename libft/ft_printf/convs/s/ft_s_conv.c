/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:06:53 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:43:32 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_s_flags[] =
{
	ft_s_precision, ft_c_zero, ft_d_padding
};

char		*ft_launch_s_flags(char **argcvd, t_flags *flags)
{
	int			nb_flags;

	nb_flags = 0;
	while (nb_flags < 3)
	{
		if ((g_s_flags[nb_flags++](argcvd, flags)) == -1)
			return (NULL);
	}
	return (*argcvd);
}

char		*ft_n_s(t_datas *datas, t_flags *flags)
{
	va_list	copy;
	char	*arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, char *);
	va_end(copy);
	return (arg);
}

static char	*ft_get_argcvd(char **argcvd)
{
	if (*argcvd == NULL)
	{
		if (!(*argcvd = ft_strdup("(null)")))
			return (NULL);
	}
	else
	{
		if (!(*argcvd = ft_strdup(*argcvd)))
			return (NULL);
	}
	return (*argcvd);
}

char		*ft_get_s_conv(t_datas *datas)
{
	char	*argcvd;
	t_flags	flags;

	if (ft_strchr(datas->flags, 'l'))
		return (ft_get_ls_conv(datas));
	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit(datas));
	if (datas->un_ord == 1)
		argcvd = ft_n_s(datas, &flags);
	else
		argcvd = va_arg(datas->ap, char *);
	if (!(argcvd = ft_get_argcvd(&argcvd)))
		return (ft_exit(datas));
	if (!(argcvd = ft_launch_s_flags(&argcvd, &flags)))
		return (ft_exit_conv(datas, argcvd));
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
