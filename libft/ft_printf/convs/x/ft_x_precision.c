/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:27:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/23 12:07:46 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_precision(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;
	int		n;

	n = 0;
	if (**argcvd == '0' && flags->pointer == 0)
		flags->diese = 0;
	if (**argcvd == '0' && flags->precision == 0)
		n = 1;
	else if (flags->precision < 0
			|| flags->precision < (int)ft_strlen(*argcvd))
		return (0);
	if (!(tmp = ft_strnew(flags->precision)))
		return (-1);
	nb_o = n;
	while (nb_o < ((flags->precision) - (int)((ft_strlen(*argcvd)))))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, *argcvd + n);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
