/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:32:06 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/27 20:18:58 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddchar(char *s, int c)
{
	char	*new;
	int		newlen;
	int		i;
	int		o;

	i = 0;
	newlen = ft_strlen(s) + sizeof(c);
	if (!(new = ft_strnew(newlen)))
		return (NULL);
	if (!s)
	{
		*new = c;
		return (new);
	}
	while (*s)
		new[i++] = *s++;
	o = 0;
	new[i++] = c;
	return (new);
}
