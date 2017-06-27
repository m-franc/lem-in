/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:42:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/25 12:14:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		lenrev;
	char	tmp;

	if (!s)
		return (NULL);
	lenrev = ft_strlen(s) - 1;
	i = 0;
	while (i < lenrev)
	{
		tmp = s[lenrev];
		s[lenrev--] = s[i];
		s[i++] = tmp;
	}
	return (s);
}
