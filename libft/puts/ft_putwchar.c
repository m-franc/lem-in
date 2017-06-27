/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:53:06 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 18:06:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wint_t wchar)
{
	char	*unicode;

	if (!(unicode = ft_wctoa(wchar)))
		return ;
	ft_putstr(unicode);
	ft_strdel(&unicode);
}
