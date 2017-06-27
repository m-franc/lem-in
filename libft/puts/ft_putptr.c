/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:28:33 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 18:59:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(const void *value)
{
	char				*ptr;

	if (!value)
		return ;
	if (!(ptr = ft_vtop(value)))
		return ;
	ft_putstr(ptr);
	ft_strdel(&ptr);
}
