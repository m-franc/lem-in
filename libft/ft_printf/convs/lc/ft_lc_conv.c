/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lc_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:55:25 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:29:42 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags_func	g_lc_flags[] =
{
	ft_c_zero, ft_c_padding,
};

static char		*ft_launch_lc_flags(char **argcvd, t_flags *flags)
{
	int			nb_flags;

	nb_flags = 0;
	while (nb_flags < 2)
	{
		if ((g_lc_flags[nb_flags++](argcvd, flags)) == -1)
			return (NULL);
	}
	return (*argcvd);
}

static char		*ft_lc_exist(t_datas *datas, t_flags *flags, int arg)
{
	char		*argcvd;

	if (!(argcvd = ft_wctoa(arg)))
		return (ft_exit(datas));
	if (!(argcvd = ft_launch_lc_flags(&argcvd, flags)))
		return (ft_exit_conv(datas, argcvd));
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len = ft_strlen(datas->result);
	ft_strdel(&argcvd);
	return (datas->result);
}

static char		*ft_lc_dont_exist(t_datas *datas, t_flags *flags, wint_t arg)
{
	char		*argcvd;

	if (!(argcvd = ft_wctoa(arg)))
		return (ft_exit(datas));
	if (flags->padding < 0)
	{
		flags->padding *= -1;
		flags->less = 1;
	}
	if (flags->padding != 0)
		flags->padding -= 1;
	if (flags->less == 1)
	{
		if ((ft_zero_right_padding(&argcvd, flags, datas)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	else
	{
		if ((ft_zero_left_padding(&argcvd, flags, datas)) == -1)
			return (ft_exit_conv(datas, argcvd));
	}
	return (datas->result);
}

static char		*ft_prepare_lc_conv(t_datas *datas, t_flags *flags, wint_t arg)
{
	if (arg == 0)
	{
		if (!(datas->result = ft_lc_dont_exist(datas, flags, arg)))
			return (ft_exit(datas));
	}
	else
	{
		if (!(datas->result = ft_lc_exist(datas, flags, arg)))
			return (ft_exit(datas));
	}
	return (datas->result);
}

char			*ft_get_lc_conv(t_datas *datas)
{
	va_list		copy;
	wint_t		arg;
	t_flags		flags;

	if ((ft_flags_init(datas, &flags)) == -1)
		return (ft_exit(datas));
	if (datas->un_ord == 1)
	{
		va_copy(copy, datas->ap);
		while (flags.dollar-- > 0)
			va_arg(copy, void *);
		arg = va_arg(copy, wint_t);
		va_end(copy);
	}
	else
		arg = va_arg(datas->ap, wint_t);
	if (!(datas->result = ft_prepare_lc_conv(datas, &flags, arg)))
		return (NULL);
	return (datas->result);
}
