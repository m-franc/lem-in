/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:19:05 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/24 22:14:34 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_exit_current(t_datas *datas)
{
	if (datas->result)
		ft_strdel(&(datas->result));
	if (datas->flags)
		ft_strdel(&(datas->flags));
	datas->len = -1;
	return (datas->len);
}

int		ft_exit_noconv(t_datas *datas, char *tmpsf)
{
	if (datas->result)
		ft_strdel(&(datas->result));
	if (datas->flags)
		ft_strdel(&(datas->flags));
	if (tmpsf)
		ft_strdel(&tmpsf);
	datas->len = -1;
	return (datas->len);
}

char	*ft_exit_unconv(t_datas *datas, char *ucvchar)
{
	if (datas->result)
		ft_strdel(&(datas->result));
	if (datas->flags)
		ft_strdel(&(datas->flags));
	if (ucvchar)
		ft_strdel(&ucvchar);
	datas->len = -1;
	return (NULL);
}
