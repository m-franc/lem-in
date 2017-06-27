/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:08:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:22:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_eoc(char **s, char *buffpc, int *i)
{
	char	*eoc;
	char	*new;
	char	*color;

	if (!(eoc = ft_strdup("{eoc}")))
		return (-1);
	if (!(ft_strnstr(*s + *i, eoc, ft_strlen(eoc))))
		return (ft_exit_clrnofind(eoc));
	if (!(color = ft_strjoin(buffpc, EOC)))
		return (ft_exit_color_error(eoc));
	*i += ft_strlen(eoc);
	if (!(new = ft_strjoin(color, (*s + *i))))
		return (ft_exit_multicolor(eoc, color));
	ft_strdel(&eoc);
	ft_strdel(s);
	ft_strdel(&color);
	ft_strdel(&buffpc);
	*s = new;
	return (1);
}
