/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:20:37 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_cyan(char **s, char *buffpc, int *i)
{
	char	*cyan;
	char	*new;
	char	*color;

	if (!(cyan = ft_strdup("{cyan}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, cyan, ft_strlen(cyan))))
		return (ft_exit_clrnofind(cyan));
	if (!(color = ft_strjoin(buffpc, CYAN)))
		return (ft_exit_color_error(cyan));
	*i += ft_strlen(cyan);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(cyan, color));
	ft_strdel(&cyan);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
