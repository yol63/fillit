/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:47:03 by romarash          #+#    #+#             */
/*   Updated: 2019/09/25 18:32:38 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	if (!(newlist = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		newlist->content_size = 0;
		newlist->content = NULL;
		newlist->next = NULL;
		return (newlist);
	}
	newlist->content_size = content_size;
	if (!(newlist->content = malloc(content_size)))
	{
		free(newlist);
		return (NULL);
	}
	ft_memcpy(newlist->content, content, content_size);
	newlist->next = NULL;
	return (newlist);
}
