/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintendl_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:40:15 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/04 19:40:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putintendl_fd(long long int n, int fd, int base, char *baselist)
{
	ft_putint_fd(n, fd, base, baselist);
	ft_putchar_fd('\n', fd);
}
