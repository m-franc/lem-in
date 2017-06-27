/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:06:53 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:50:20 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_ls_flags[] =
{
	ft_ls_precision, ft_c_zero, ft_d_padding
};

static wchar_t	*ft_n_ls(t_datas *datas, t_flags *flags)
{
	va_list		copy;
	wchar_t		*arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, wchar_t *);
	va_end(copy);
	return (arg);
}

static char		*ft_launch_ls_flags(char **argcvd, t_flags *flags)
{
	int			nb_flags;

	nb_flags = 0;
	while (nb_flags < 3)
	{
		if ((g_ls_flags[nb_flags++](argcvd, flags)) == -1)
			return (NULL);
	}
	return (*argcvd);
}

static char		*ft_get_argcvd(wchar_t **argcvd)
{
	char		*newarg;

	if (*argcvd == NULL)
	{
		if (!(newarg = ft_strdup("(null)")))
			return (NULL);
		return (newarg);
	}
	else
	{
		if (!(newarg = ft_wstrtoa(*argcvd)))
			return (NULL);
		return (newarg);
	}
}

char			*ft_get_ls_conv(t_datas *datas)
{
	char		*argcvd;
	wchar_t		*arg;
	t_flags		flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit(datas));
	if (datas->un_ord == 1)
		arg = ft_n_ls(datas, &flags);
	else
		arg = va_arg(datas->ap, wchar_t *);
	if (!(argcvd = ft_get_argcvd(&arg)))
		return (ft_exit(datas));
	if (!(argcvd = ft_launch_ls_flags(&argcvd, &flags)))
		return (ft_exit_conv(datas, argcvd));
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
