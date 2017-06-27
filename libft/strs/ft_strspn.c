/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:14:56 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/14 16:59:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	count;

	if (!s || !accept)
		return (0);
	count = 0;
	while (*s)
	{
		if (ft_strchr(accept, *s))
			count++;
		else
			break ;
		s++;
	}
	return (count);
}
