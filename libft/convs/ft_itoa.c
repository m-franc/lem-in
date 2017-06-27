/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:58:25 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/22 17:50:46 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*ft_itoa(long long n, int base, char *baselist)
{
	int		len;
	char	*result;

	if (base >= 17 && base < 2)
		return (NULL);
	len = ft_ilen(n, base);
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (!(result = ft_strnew(len)))
		return (NULL);
	if (n < 0 && base == 10)
		result[0] = '-';
	if (n < 0)
		n = -n;
	result[len--] = '\0';
	if (n == 0 && result[len] != '-')
		result[len--] = baselist[n % base];
	while (n != 0)
	{
		result[len--] = baselist[n % base];
		n /= base;
	}
	return (result);
}
