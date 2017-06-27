/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplsit_tolist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:09:14 by mfranc            #+#    #+#             */
/*   Updated: 2017/02/10 13:42:38 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_slc(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

t_list			*ft_strsplit_tolist(char const *s, char c)
{
	t_list			*new;
	t_list			*tmp;
	int				o;

	o = 0;
	while (s[o] == c)
		o++;
	new = ft_lstnew(ft_strsub(s, o, ft_slc(s + o, c)), ft_slc(s + o, c));
	tmp = new;
	while (s[o])
	{
		if (s[o] != c && s[o])
		{
			new->next = ft_lstnew(ft_strsub(s, o, ft_slc(s
							+ o, c)), ft_slc(s + o, c));
			new = new->next;
			while (s[o] != c && s[o])
				o++;
		}
		else
			o++;
	}
	free(tmp);
	return (tmp->next);
}
