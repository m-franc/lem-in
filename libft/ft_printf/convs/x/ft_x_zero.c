/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:09:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/23 12:48:59 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_zero(char **argcvd, t_flags *flags)
{
	if (flags->zero == 0 || flags->padding == 0 || flags->precision >= 0)
		return (0);
	else
	{
		flags->precision = flags->padding;
		if (flags->diese == 1)
			flags->precision -= 2;
		flags->padding = 0;
		if (flags->precision < (int)ft_strlen(*argcvd))
			return (0);
		return (ft_x_precision(argcvd, flags));
	}
}
