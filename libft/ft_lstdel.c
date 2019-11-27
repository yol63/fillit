/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:02:06 by romarash          #+#    #+#             */
/*   Updated: 2019/09/30 21:36:22 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	if (alst && del)
	{
		while (*alst)
		{
			list = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = list;
		}
		free(*alst);
		*alst = NULL;
	}
}
