/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:54:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/15 16:41:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	o;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			o = i;
			while (s1[i] == s2[j] && s2[j])
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)s1 + o);
			i = o;
		}
		i++;
	}
	return (NULL);
}
