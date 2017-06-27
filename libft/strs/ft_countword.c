/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:14:05 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/21 19:47:40 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (s[i])
	{
		if (ft_isword(s[i]) == 1 && ft_isword(s[i + 1]) == 0)
			result++;
		i++;
	}
	return (result);
}
