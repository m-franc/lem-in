/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bold.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:20:30 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_bold(char **s, char *buffpc, int *i)
{
	char	*bold;
	char	*new;
	char	*color;

	if (!(bold = ft_strdup("{bold}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, bold, ft_strlen(bold))))
		return (ft_exit_clrnofind(bold));
	if (!(color = ft_strjoin(buffpc, BOLD)))
		return (ft_exit_color_error(bold));
	*i += ft_strlen(bold);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(bold, color));
	ft_strdel(&bold);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
