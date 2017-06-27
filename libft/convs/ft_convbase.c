/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convbase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 17:19:40 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/22 19:58:45 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convbase(char *value, int old_base, int new_base, char *bl)
{
	int		len;
	int		b10;
	int		i;

	i = 0;
	if (old_base > 16 || old_base < 2 || !value)
		return (NULL);
	if (old_base == 10)
		return (ft_itoa(ft_atoi(value), new_base, bl));
	len = ft_strlen(value) - 1;
	b10 = 0;
	while (len >= 0)
		b10 += (ft_strlenuntil(bl, value[i++]) * ft_power(old_base, len--));
	return (ft_itoa(b10, new_base, bl));
}
