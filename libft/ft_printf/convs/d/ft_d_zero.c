/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:09:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 16:43:07 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d_zero(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;
	int		n;

	n = 0;
	if (flags->zero == 0 || flags->padding == 0 || flags->precision >= 0)
		return (0);
	if (**argcvd == '-')
		n = 1;
	if (!(tmp = ft_strnew(flags->padding + n)))
		return (-1);
	if (**argcvd == '-')
		tmp[0] = '-';
	nb_o = n;
	if ((flags->plus == 1 || flags->space == 1) && n == 0)
		flags->padding -= 1;
	while (nb_o < (int)((flags->padding + n) - ((ft_strlen(*argcvd)))))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, *argcvd + n);
	ft_strdel(argcvd);
	*argcvd = tmp;
	flags->padding = 0;
	return (1);
}

int	ft_o_zero(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->zero == 0 || flags->padding == 0 || flags->precision >= 0)
		return (0);
	if (!(tmp = ft_strnew(flags->padding)))
		return (-1);
	nb_o = 0;
	while (nb_o < (int)((flags->padding) - ((ft_strlen(*argcvd)))))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	flags->padding = 0;
	return (1);
}

int	ft_f_zero(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->zero == 0 || flags->padding == 0)
		return (0);
	if (!(tmp = ft_strnew(flags->padding)))
		return (-1);
	nb_o = 0;
	while (nb_o < (int)((flags->padding) - ((ft_strlen(*argcvd)))))
		tmp[nb_o++] = '0';
	tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	flags->padding = 0;
	return (1);
}

int	ft_c_zero(char **argcvd, t_flags *flags)
{
	char	*tmp;
	int		nb_o;

	if (flags->zero == 0)
		return (0);
	else
	{
		if (!(tmp = ft_strnew(flags->padding)))
			return (-1);
		nb_o = 0;
		while (nb_o < (int)(flags->padding - (ft_strlen(*argcvd))))
			tmp[nb_o++] = '0';
		tmp = ft_strcat(tmp, *argcvd);
		ft_strdel(argcvd);
		*argcvd = tmp;
		flags->padding = 0;
		return (1);
	}
}
