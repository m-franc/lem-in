/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:14:08 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/25 13:14:01 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_vtob(const void *c, size_t size)
{
	unsigned char	msq;
	char			*result;
	size_t			i;
	size_t			o;

	if (!c)
		return (NULL);
	i = 0;
	o = 0;
	if (!(result = ft_strnew(9 * size)))
		return (NULL);
	while (o < size)
	{
		msq = 0b0000001;
		while (msq)
		{
			result[i++] = (*(char*)c & msq) ? '1' : '0';
			msq = (msq << 1);
		}
		if (i != 9 * size - 1)
			result[i++] = 32;
		c++;
		o++;
	}
	return (ft_strrev(result));
}
