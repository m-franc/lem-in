/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_green.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/31 12:36:40 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_green(char **s, char *buffpc, int *i)
{
	char	*green;
	char	*new;
	char	*color;

	if (!(green = ft_strdup("{green}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, green, ft_strlen(green))))
		return (ft_exit_clrnofind(green));
	if (!(color = ft_strjoin(buffpc, GREEN)))
		return (ft_exit_color_error(green));
	*i += ft_strlen(green);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(green, color));
	ft_strdel(&green);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
