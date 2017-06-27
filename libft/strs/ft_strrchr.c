/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:38:18 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/21 16:53:27 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	int		find;

	len = 0;
	find = -1;
	while (str[len])
	{
		if (str[len] == (unsigned char)c)
			find = len;
		len++;
	}
	if (find != -1)
		return ((char*)str + find);
	if (str[len] == c)
		return ((char*)&str[len]);
	else
		return (NULL);
}
