/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:38:43 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 17:54:04 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_complete_precision(char **second, int l_sec)
{
	char		*complete;

	if (!(complete = ft_strnew(l_sec)))
		return (NULL);
	while (l_sec-- > 0)
		complete[l_sec] = '0';
	if (!(complete = ft_strjoin(*second, complete)))
		return (NULL);
	ft_strdel(second);
	return (complete);
}

static char		*ft_get_lastprecision(long double n)
{
	char		*sec;
	char		*cp;

	sec = NULL;
	if (!(sec = ft_itoa(n, 10, BASEUP)))
		return (NULL);
	if (ft_strlen(sec) < 6)
	{
		if (!(cp = ft_complete_precision(&sec, 6 - ft_strlen(sec))))
			return (NULL);
		return (cp);
	}
	return (sec);
}

static char		*ft_precision_management(long double n, int precision)
{
	char		*sec;

	if (precision != 6)
	{
		if (!(sec = ft_itoa(n, 10, BASEUP)))
			return (NULL);
		return (sec);
	}
	else
	{
		if (!(sec = ft_get_lastprecision(n)))
			return (NULL);
		return (sec);
	}
}

char			*ft_ftoa(long double n, int precision)
{
	char		*result;
	char		*entier;
	char		*second;
	char		*getdot;

	if (!(entier = ft_itoa(n, 10, BASEUP)))
		return (NULL);
	n = ((n - ft_atoi(entier)));
	n = ABS(n);
	n *= ft_power(10, precision);
	n += 0.5;
	if (precision == 0)
		return (entier);
	if (!(second = ft_precision_management(n, precision)))
		return (NULL);
	if (!(getdot = ft_straddchar(entier, '.')))
		return (NULL);
	ft_strdel(&entier);
	if (!(result = ft_strjoin(getdot, second)))
		return (NULL);
	ft_strdel(&getdot);
	ft_strdel(&second);
	return (result);
}
