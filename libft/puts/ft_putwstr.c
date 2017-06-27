/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:43:22 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 17:43:44 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr(wchar_t *str)
{
	char	*unicode;

	if (!(unicode = ft_wstrtoa(str)))
		return ;
	ft_putstr(unicode);
	ft_strdel(&unicode);
}
