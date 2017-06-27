/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:05:55 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/22 18:19:47 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_power(long long nb, int power)
{
	if (nb == 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	nb = nb * ft_power(nb, power - 1);
	return (nb);
}
