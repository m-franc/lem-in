/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 16:10:01 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/04 18:25:51 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					ft_exit_error(void)
{
	ft_printf("%w{red}ERROR{eoc}\n", 2);
	exit(1);
}

int						ft_exit_function(int return_value, void *st_elem,
		void *nd_elem, void *rd_elem)
{
	ft_memdel(&st_elem);
	ft_memdel(&nd_elem);
	ft_memdel(&rd_elem);
	return (return_value);
}
