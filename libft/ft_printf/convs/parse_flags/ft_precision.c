/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:00:55 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 17:45:50 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_n_arg_precision(t_datas *datas, int n, t_flags *flags, size_t *i)
{
	va_list	copy;
	int		star;

	va_copy(copy, datas->ap);
	while (n-- > 0)
		va_arg(copy, void *);
	star = va_arg(copy, int);
	va_end(copy);
	flags->precision = star;
	*i += ft_ilen(n, 10) + 1;
	return (1);
}

int		ft_arg_precision(t_datas *datas, char *strflag,
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
				return (ft_n_arg_precision(datas, result - 1, flags, i));
			else
				return (-1);
		}
		else
			return (-1);
	}
	flags->precision = va_arg(datas->ap, int);
	*i += 1;
	return (1);
}

int		ft_precision(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	int		result;
	int		len;

	if (strflag[0] != '.')
		return (0);
	*i = 1;
	if (strflag[1] == '*')
		return (ft_arg_precision(datas, strflag + 2, flags, i));
	else if (strflag[1] >= '1' && strflag[1] <= '9')
	{
		result = ft_atoi(strflag + 1);
		len = ft_ilen(result, 10);
		if (strflag[len + 1] == '$')
			return (-1);
		flags->precision = result;
		*i += len;
		return (1);
	}
	else
		flags->precision = 0;
	return (1);
}
