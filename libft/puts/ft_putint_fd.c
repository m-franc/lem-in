/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:50:12 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/03 15:14:02 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putint_fd(long long n, int fd, int base, char *baselist)
{
	char	*number;

	if (fd < 0 || !baselist)
		return ;
	if (!(number = ft_itoa(n, base, baselist)))
		return ;
	ft_putstr_fd(number, fd);
	ft_strdel(&number);
}
