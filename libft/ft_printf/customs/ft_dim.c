/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:31:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dim(char **s, char *buffpc, int *i)
{
	char	*dim;
	char	*new;
	char	*color;

	if (!(dim = ft_strdup("{dim}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, dim, ft_strlen(dim))))
		return (ft_exit_clrnofind(dim));
	if (!(color = ft_strjoin(buffpc, DIM)))
		return (ft_exit_color_error(dim));
	*i += ft_strlen(dim);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(dim, color));
	ft_strdel(&dim);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
