/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:39:39 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/03 15:13:09 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuint_fd(unsigned long long n, int fd, int base, char *baselist)
{
	char	*number;

	if (fd < 0 || !baselist)
		return ;
	if (!(number = ft_uitoa(n, base, baselist)))
		return ;
	ft_putstr_fd(number, fd);
	ft_strdel(&number);
}
