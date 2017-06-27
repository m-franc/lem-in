/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nulchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:07:36 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 17:27:39 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aff_nulchar_clean(t_datas *datas)
{
	datas->len = ft_strlen(datas->result);
	datas->cplen = datas->len + datas->cplen + 1;
	write(datas->fd, datas->result, datas->len);
	write(datas->fd, "\0", 1);
	ft_strdel(&(datas->result));
	datas->len = 0;
}

void	ft_aff_nulchar(t_datas *datas)
{
	datas->len = ft_strlen(datas->result);
	datas->cplen = datas->len + datas->cplen + 1;
	write(datas->fd, datas->result, datas->len);
	write(1, "\0", 1);
	datas->len = 0;
}

int		ft_zero_right_padding(char **argcvd, t_flags *flags, t_datas *datas)
{
	ft_aff_nulchar(datas);
	if (!(*argcvd = ft_launch_c_flags(argcvd, flags)))
		return (-1);
	if (!(datas->result = ft_strdup(*argcvd)))
		return (-1);
	ft_strdel(argcvd);
	return (1);
}

int		ft_zero_left_padding(char **argcvd, t_flags *flags, t_datas *datas)
{
	if (!(*argcvd = ft_launch_c_flags(argcvd, flags)))
		return (-1);
	if (!(datas->result = ft_strjoin(datas->result, *argcvd)))
		return (-1);
	ft_aff_nulchar_clean(datas);
	if (!(datas->result = ft_strnew(0)))
		return (-1);
	ft_strdel(argcvd);
	return (1);
}
