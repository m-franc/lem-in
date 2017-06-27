/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_datasmanager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:32:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/27 16:05:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_last_datasmanager(char conv, char **lastdatas)
{
	if (conv == 'n' || conv == 'w' || conv == 'N')
		*lastdatas = NULL;
	if (lastdatas && (conv != 'n' || conv != 'w' || conv != 'N'))
		ft_strdel(lastdatas);
}
