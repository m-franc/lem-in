/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:39:02 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 19:39:03 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putint(long long int n, int base, char *baselist)
{
	char	*number;

	if (!baselist)
		return ;
	if (!(number = ft_itoa(n, base, baselist)))
		return ;
	ft_putstr(number);
	ft_strdel(&number);
}
