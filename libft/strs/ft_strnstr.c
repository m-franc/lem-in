/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:20:12 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/19 18:12:41 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i] == s2[j] && s2[j] && i < n)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)s1 + i - j);
		else
			i = i - j;
		i++;
	}
	return (NULL);
}
