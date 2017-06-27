/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:19:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 21:30:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_exit_conv(t_datas *datas, char *argcvd)
{
	if (datas->result)
		ft_strdel(&(datas->result));
	if (datas->flags)
		ft_strdel(&(datas->flags));
	if (argcvd)
		ft_strdel(&argcvd);
	datas->len = -1;
	return (NULL);
}
