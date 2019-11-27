/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:08:34 by romarash          #+#    #+#             */
/*   Updated: 2019/09/30 21:39:25 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *newlist;
	t_list *res;

	if (!lst || !f || !(newlist = malloc(sizeof(t_list)))
			|| !(newlist = f(lst)))
		return (NULL);
	lst = lst->next;
	res = newlist;
	while (lst)
	{
		if (!(newlist->next = malloc(sizeof(t_list)))
				|| !(newlist->next = f(lst)))
		{
			ft_free(res);
			return (NULL);
		}
		lst = lst->next;
		newlist = newlist->next;
	}
	return (res);
}
