/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:18:07 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 16:03:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	void	*area;

	if (!n)
		return (NULL);
	if (!(area = malloc(n)))
		return (NULL);
	ft_bzero(area, n);
	return (area);
}
