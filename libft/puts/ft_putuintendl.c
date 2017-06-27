/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuintendl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:38:15 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 19:40:02 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuintendl(unsigned long long n, int base, char *baselist)
{
	ft_putuint(n, base, baselist);
	ft_putchar('\n');
}
