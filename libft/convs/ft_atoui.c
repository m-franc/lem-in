/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:52:09 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 19:55:08 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoui(const char *str)
{
	unsigned long long	result;

	result = 0;
	while (*str)
	{
		while ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		if (*str == '-' || *str == '+')
			str++;
		while (*str >= 48 && *str <= 57)
			result = result * 10 + (*str++ - '0');
		return ((result));
		str++;
	}
	return (0);
}
