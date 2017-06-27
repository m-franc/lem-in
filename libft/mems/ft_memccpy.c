/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:00:55 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/21 11:29:22 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*srcstr;
	unsigned char	*deststr;
	size_t			i;

	srcstr = (unsigned char*)src;
	deststr = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		deststr[i] = srcstr[i];
		if (srcstr[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
