/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:17:09 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_blink(char **s, char *buffpc, int *i)
{
	char	*blink;
	char	*new;
	char	*color;

	if (!(blink = ft_strdup("{blink}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, blink, ft_strlen(blink))))
		return (ft_exit_clrnofind(blink));
	if (!(color = ft_strjoin(buffpc, BLINK)))
		return (ft_exit_color_error(blink));
	*i += ft_strlen(blink);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(blink, color));
	ft_strdel(&blink);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
