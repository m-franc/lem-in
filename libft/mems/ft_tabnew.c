/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:48:15 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/21 19:59:14 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabnew(size_t n)
{
	size_t	i;
	void	**tab;

	if (!(tab = (void**)malloc(sizeof(void*) * n + 1)))
		return (NULL);
	i = 0;
	while (i < n)
		tab[i++] = 0;
	return (tab);
}
