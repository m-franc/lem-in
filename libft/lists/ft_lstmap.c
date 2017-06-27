/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:27:36 by mfranc            #+#    #+#             */
/*   Updated: 2016/11/19 18:07:54 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(tmp = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	new = f(lst);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = (t_list*)malloc(sizeof(*new))))
			return (NULL);
		new->next = f(lst);
		lst = lst->next;
		new = new->next;
	}
	free(new);
	return (tmp);
}
