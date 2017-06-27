/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:37:31 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/14 16:59:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	count;

	if (!s || !reject)
		return (0);
	count = 0;
	while (*s)
	{
		if (!(ft_strchr(reject, *s)))
			count++;
		else
			break ;
		s++;
	}
	return (count);
}
