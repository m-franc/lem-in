/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:44:41 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 17:45:03 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwendl(wchar_t *str)
{
	char	*unicode;

	if (!(unicode = ft_wstrtoa(str)))
		return ;
	ft_putendl(unicode);
	ft_strdel(&unicode);
}
