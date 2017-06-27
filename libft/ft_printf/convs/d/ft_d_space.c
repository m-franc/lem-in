/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 19:29:22 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/12 19:43:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d_space(char **argcvd, t_flags *flags)
{
	char	*tmp;

	if (flags->space == 0 || **argcvd == '-')
		return (0);
	if (!(tmp = ft_strnew(ft_strlen(*argcvd) + 1)))
		return (-1);
	tmp[0] = ' ';
	tmp = ft_strcat(tmp, *argcvd);
	ft_strdel(argcvd);
	*argcvd = tmp;
	return (1);
}
