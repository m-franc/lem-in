/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:57:33 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 13:04:50 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*srcstr;
	char			*deststr;
	size_t			i;

	srcstr = (const char*)src;
	deststr = (char*)dest;
	i = -1;
	while (++i < n)
		*deststr++ = *srcstr++;
	return (dest);
}
