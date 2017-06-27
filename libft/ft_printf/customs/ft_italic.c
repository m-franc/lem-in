/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_italic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:25:57 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_italic(char **s, char *buffpc, int *i)
{
	char	*italic;
	char	*new;
	char	*color;

	if (!(italic = ft_strdup("{italic}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, italic, ft_strlen(italic))))
		return (ft_exit_clrnofind(italic));
	if (!(color = ft_strjoin(buffpc, ITALIC)))
		return (ft_exit_color_error(italic));
	*i += ft_strlen(italic);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(italic, color));
	ft_strdel(&italic);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
