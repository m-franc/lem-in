/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:27:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 17:29:21 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d_precision(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;
	int		n;

	n = 0;
	if (**argcvd == '0' && flags->precision == 0)
		n = 1;
	else if (flags->precision < 0
			|| flags->precision < (int)ft_strlen(*argcvd))
		return (0);
	if (**argcvd == '-')
		n = 1;
	if (!(tmp = ft_strnew(flags->precision + n)))
		return (-1);
	if (**argcvd == '-')
		tmp[0] = '-';
	nb_o = n;
	while (nb_o < (int)((flags->precision + n) - ((ft_strlen(*argcvd) - n))))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, argcvd[0] + n);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
