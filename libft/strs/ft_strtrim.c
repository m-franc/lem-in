/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:08:40 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/21 15:59:21 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	o;

	if (!s)
		return (NULL);
	o = 0;
	while (s[o] && (s[o] == ' ' || s[o] == '\t' || s[o] == '\n'))
		o++;
	i = o;
	while (s[i] && s[o])
		i++;
	i--;
	while (s[i] && s[o] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	i++;
	new = ft_strsub((char*)s, o, i - o);
	if (new == NULL)
		return (NULL);
	return (new);
}
