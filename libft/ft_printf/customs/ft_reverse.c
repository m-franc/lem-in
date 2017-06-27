/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:28:26 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_reverse(char **s, char *buffpc, int *i)
{
	char	*reverse;
	char	*new;
	char	*color;

	if (!(reverse = ft_strdup("{reverse}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, reverse, ft_strlen(reverse))))
		return (ft_exit_clrnofind(reverse));
	if (!(color = ft_strjoin(buffpc, REVERSE)))
		return (ft_exit_color_error(reverse));
	*i += ft_strlen(reverse);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(reverse, color));
	ft_strdel(&reverse);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
