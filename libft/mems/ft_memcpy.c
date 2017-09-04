/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:57:33 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/04 18:56:18 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*srcstr;
	unsigned char		*deststr;
	size_t				i;

	srcstr = (unsigned char*)src;
	deststr = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		deststr[i] = srcstr[i];
		i++;
	}
	return (dest);
}
