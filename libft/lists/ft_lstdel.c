/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:50:14 by mfranc            #+#    #+#             */
/*   Updated: 2017/09/05 18:16:00 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list	*tmp;
	t_list	*to_free;
	t_list	*curr_tmp;

	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp)
		{
			curr_tmp = tmp->next;
			to_free = tmp;
			free(to_free->content);
			to_free->content = NULL;
			to_free->content_size = 0;
			free(to_free);
			tmp = curr_tmp;
		}
		*alst = NULL;
	}
}
