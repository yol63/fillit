/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:17:20 by romarash          #+#    #+#             */
/*   Updated: 2019/09/30 20:58:37 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	list = NULL;
	if (alst && del)
	{
		list = *alst;
		del(list->content, list->content_size);
		free(*alst);
		list = NULL;
		*alst = NULL;
	}
}
