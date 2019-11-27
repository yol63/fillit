/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:54:28 by romarash          #+#    #+#             */
/*   Updated: 2019/09/30 22:35:49 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(t_list *elem))
{
	t_list *newlist;

	newlist = NULL;
	if (!list || !f)
		return ;
	newlist = list;
	while (newlist)
	{
		f(newlist);
		newlist = newlist->next;
	}
}
