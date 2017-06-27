/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 21:27:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 14:06:43 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_n_b(t_datas *datas, t_flags *flags)
{
	va_list	copy;
	void	*arg;

	va_copy(copy, datas->ap);
	while (flags->dollar-- > 0)
		va_arg(copy, void *);
	arg = va_arg(copy, void*);
	va_end(copy);
	return (arg);
}

static void	*ft_get_b(t_datas *datas, t_flags *flags, int *size)
{
	void	*arg;

	if ((ft_flags_init(datas, flags)) == -1)
		ft_exit(datas);
	if (ft_strstr(datas->flags, "hh"))
		*size = 1;
	else if (ft_strchr(datas->flags, 'h'))
		*size = 2;
	else if (ft_strchr(datas->flags, 'l'))
		*size = 8;
	if (datas->un_ord == 1)
	{
		if (!(arg = ft_n_b(datas, flags)))
			return (NULL);
	}
	else
	{
		if (!(arg = va_arg(datas->ap, void*)))
			return (NULL);
	}
	return (arg);
}

char		*ft_get_b_conv(t_datas *datas)
{
	char	*argcvd;
	void	*arg;
	int		size;
	int		*ps;
	t_flags	flags;

	size = 4;
	ps = &size;
	if (!(arg = ft_get_b(datas, &flags, ps)))
		return (ft_exit(datas));
	if (!(argcvd = ft_vtob(arg, size)))
		return (ft_exit(datas));
	if ((ft_d_padding(&argcvd, &flags)) == -1)
		ft_exit_conv(datas, argcvd);
	if (!(datas->result = ft_strjoin(datas->result, argcvd)))
		return (ft_exit_conv(datas, argcvd));
	datas->len += ft_strlen(argcvd);
	ft_strdel(&argcvd);
	return (datas->result);
}
