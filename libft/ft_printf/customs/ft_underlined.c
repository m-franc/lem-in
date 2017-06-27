/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_underlined.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:28:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_underlined(char **s, char *buffpc, int *i)
{
	char	*underlined;
	char	*new;
	char	*color;

	if (!(underlined = ft_strdup("{underlined}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, underlined, ft_strlen(underlined))))
		return (ft_exit_clrnofind(underlined));
	if (!(color = ft_strjoin(buffpc, UNDERLINED)))
		return (ft_exit_color_error(underlined));
	*i += ft_strlen(underlined);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(underlined, color));
	ft_strdel(&underlined);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
