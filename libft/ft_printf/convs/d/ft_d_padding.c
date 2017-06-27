/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:27:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 19:43:07 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_right_padding(char *tmp, char **argcvd, t_flags *flags)
{
	int	nb_o;

	tmp = ft_strncpy(tmp, *argcvd, ft_strlen(*argcvd));
	nb_o = ft_strlen(*argcvd);
	while (nb_o < flags->padding)
		tmp[nb_o++] = ' ';
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}

int			ft_d_padding(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->padding == 0 || flags->padding > 1000)
		return (0);
	if (flags->padding < 0)
	{
		flags->padding *= -1;
		flags->less = 1;
	}
	if ((int)ft_strlen(*argcvd) > flags->padding)
		return (0);
	nb_o = -1;
	if (!(tmp = ft_strnew(flags->padding)))
		return (-1);
	if (flags->less == 1)
		return (ft_right_padding(tmp, argcvd, flags));
	while (++nb_o < (int)((flags->padding) - ((ft_strlen(*argcvd)))))
		tmp[nb_o] = ' ';
	tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
