/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:09:22 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/20 17:21:07 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*srcstr;
	unsigned char		*deststr;

	srcstr = (unsigned char*)src;
	deststr = (unsigned char*)dest;
	if (srcstr < deststr)
	{
		srcstr = srcstr + n - 1;
		deststr = deststr + n - 1;
		while (n-- > 0)
			*deststr-- = *srcstr--;
	}
	else
	{
		while (n-- > 0)
			*deststr++ = *srcstr++;
	}
	return (dest);
}
