/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:27:57 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_red(char **s, char *buffpc, int *i)
{
	char	*red;
	char	*new;
	char	*color;

	if (!(red = ft_strdup("{red}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, red, ft_strlen(red))))
		return (ft_exit_clrnofind(red));
	if (!(color = ft_strjoin(buffpc, RED)))
		return (ft_exit_color_error(red));
	*i += ft_strlen(red);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(red, color));
	ft_strdel(&red);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
