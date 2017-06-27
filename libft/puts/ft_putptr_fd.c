/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:39:22 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 19:39:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(const void *value, int fd)
{
	char				*ptr;

	if (!value)
		return ;
	if (!(ptr = ft_vtop(value)))
		return ;
	ft_putstr_fd(ptr, fd);
	ft_strdel(&ptr);
}
