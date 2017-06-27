/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 13:05:22 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 20:52:07 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstrtoa(wchar_t *str)
{
	char	*result;
	char	*currc;

	if (!str)
		return (NULL);
	if (!(result = ft_strnew(ft_wstrlen(str))))
		return (NULL);
	while (*str)
	{
		if (!(currc = ft_wctoa(*str++)))
		{
			ft_strdel(&result);
			return (NULL);
		}
		result = ft_strcat(result, currc);
		ft_strdel(&currc);
	}
	return (result);
}
