/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lzdps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:17:56 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 17:41:11 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_less(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	(void)datas;
	if (strflag[0] != '-')
		return (0);
	else
	{
		flags->less = 1;
		flags->zero = 0;
		*i = 1;
		return (1);
	}
}

int	ft_zero(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	(void)datas;
	if (strflag[0] != '0')
		return (0);
	else
	{
		if (flags->less == 1)
			return (0);
		flags->zero = 1;
		*i = 1;
		return (1);
	}
}

int	ft_diese(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	(void)datas;
	if (strflag[0] != '#')
		return (0);
	else
	{
		flags->diese = 1;
		*i = 1;
		return (1);
	}
}

int	ft_plus(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	(void)datas;
	if (strflag[0] != '+')
		return (0);
	else
	{
		flags->plus = 1;
		flags->space = 0;
		*i = 1;
		return (1);
	}
}

int	ft_space(t_datas *datas, char *strflag, t_flags *flags, size_t *i)
{
	(void)datas;
	if (strflag[0] != ' ')
		return (0);
	else
	{
		if (flags->plus == 1)
			return (0);
		flags->space = 1;
		*i = 1;
		return (1);
	}
}
