/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:36:58 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 17:34:09 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ls_precision(char **argcvd, t_flags *flags)
{
	char	*tmp;

	if (flags->precision < 0
			|| flags->precision >= (int)ft_strlen(*argcvd))
		return (0);
	if (flags->precision > 0)
	{
		while ((argcvd[0][flags->precision] & 0x40) == 0
				|| (argcvd[0][flags->precision] & 0xc0) == 0)
			flags->precision -= 1;
	}
	if (!(tmp = ft_strsub(*argcvd, 0, flags->precision)))
		return (-1);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
