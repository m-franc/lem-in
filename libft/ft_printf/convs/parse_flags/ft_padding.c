/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:00:55 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 19:30:35 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_n_arg_padding(t_datas *datas, int n, t_flags *flags, size_t *i)
{
	va_list	copy;
	int		star;

	va_copy(copy, datas->ap);
	while (n-- > 0)
		va_arg(copy, void *);
	star = va_arg(copy, int);
	va_end(copy);
	flags->padding = star;
	*i = ft_ilen(n, 10) + 1;
	return (1);
}

int		ft_arg_padding(t_datas *datas, char *strflag,
		t_flags *flags, size_t *i)
{
	int	result;
	int	len;

	if (datas->un_ord == 1)
	{
		if (strflag[0] >= '1' && strflag[0] <= '9')
		{
			result = ft_atoi(strflag);
			len = ft_ilen(result, 10);
			if (strflag[len] == '$')
				return (ft_n_arg_padding(datas, result - 1, flags, i));
			else
				return (-1);
		}
		else
			return (-1);
	}
	*i = 1;
	flags->padding = va_arg(datas->ap, int);
	return (1);
}

int		ft_padding(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	int		result;
	int		len;

	if (strflag[0] < '1' && strflag[0] > '9')
		return (0);
	else if (strflag[0] == '*')
		return (ft_arg_padding(datas, strflag + 1, flags, i));
	else if (strflag[0] >= '1' && strflag[0] <= '9')
	{
		result = ft_atoi(strflag);
		len = ft_ilen(result, 10);
		if (strflag[len] == '$')
		{
			*i = len + 1;
			return (flags->dollar = result - 1);
		}
		flags->padding = result;
		*i = len;
		return (1);
	}
	return (0);
}
