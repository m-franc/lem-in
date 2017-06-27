/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:52:30 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/05 17:25:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			size++;
		else if (str[i] <= 0x7FF)
			size += 2;
		else if (str[i] <= 0xFFFF)
			size += 3;
		else if (str[i] <= 0x10FFFF)
			size += 4;
		i++;
	}
	return (size);
}
