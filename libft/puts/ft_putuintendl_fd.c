/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuintendl_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:37:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/16 20:45:50 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuintendl_fd(unsigned long long n,
		int fd, int base, char *baselist)
{
	ft_putuint_fd(n, fd, base, baselist);
	ft_putchar('\n');
}
