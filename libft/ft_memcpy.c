/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:01:15 by romarash          #+#    #+#             */
/*   Updated: 2019/09/22 15:49:12 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*srcs;

	i = 0;
	if (!dest && !src)
		return (NULL);
	srcs = (unsigned char*)src;
	res = (unsigned char*)dest;
	while (i < n)
	{
		res[i] = srcs[i];
		i++;
	}
	return (dest);
}
