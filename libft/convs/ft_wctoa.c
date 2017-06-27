/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:16:00 by mfranc            #+#    #+#             */
/*   Updated: 2017/03/29 13:13:48 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get4bytewchar(wint_t uchar)
{
	int			tmp;
	int			tmp2;
	int			tmp3;
	char		*result;

	if (!(result = ft_strnew(5)))
		return (NULL);
	tmp = (uchar & 0xFC0) << 2;
	tmp2 = (uchar & 0x3F000) << 4;
	tmp3 = (uchar & 0x1C0000) << 6;
	tmp3 = (uchar & 0x3F) | tmp3 | tmp2 | tmp;
	tmp3 = tmp3 ^ 0xF0808080;
	result[0] = tmp3 >> 24;
	result[1] = tmp3 >> 16;
	result[2] = tmp3 >> 8;
	result[3] = tmp3;
	return (result);
}

static	char	*get3bytewchar(wint_t uchar)
{
	int			tmp;
	int			tmp2;
	char		*result;

	if (!(result = ft_strnew(4)))
		return (NULL);
	ft_bzero(result, 4);
	tmp2 = (uchar & 0xFC0) << 2;
	tmp = (uchar & 0xF000) << 4;
	tmp2 = (uchar & 0x3F) | tmp2 | tmp;
	tmp2 = tmp2 ^ 0xE08080;
	result[0] = tmp2 >> 16;
	result[1] = tmp2 >> 8;
	result[2] = tmp2;
	return (result);
}

static	char	*get2bytewchar(wint_t uchar)
{
	int			tmp;
	char		*result;

	if (!(result = ft_strnew(3)))
		return (NULL);
	ft_bzero(result, 3);
	tmp = (uchar & 0xFC0) << 2;
	tmp = (uchar & 0x3F) | tmp;
	tmp = tmp ^ 0xc080;
	result[0] = tmp >> 8;
	result[1] = tmp;
	return (result);
}

char			*ft_wctoa(wint_t uchar)
{
	if ((uchar >= 0 && uchar <= 127) && MB_CUR_MAX >= 1)
		return (ft_straddchar(NULL, uchar));
	else if ((uchar >= 0 && uchar <= 255) && MB_CUR_MAX == 1)
		return (ft_straddchar(NULL, uchar));
	else if ((uchar >= 127 && uchar <= 2047) && MB_CUR_MAX >= 2)
		return (get2bytewchar(uchar));
	else if ((uchar >= 2048 && uchar <= 65535) && MB_CUR_MAX >= 3)
		return (get3bytewchar(uchar));
	else if ((uchar >= 65536 && uchar <= 1114111) && MB_CUR_MAX >= 4)
		return (get4bytewchar(uchar));
	return (NULL);
}
