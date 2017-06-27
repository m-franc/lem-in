/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 20:02:18 by mfranc            #+#    #+#             */
/*   Updated: 2017/05/29 18:39:25 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char ***tab)
{
	char	**cpy;
	int		i;

	if (!tab || !*tab)
		return ;
	cpy = *tab;
	i = 0;
	while (cpy[i])
	{
		ft_strdel(&cpy[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
