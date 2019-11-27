/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:30:03 by romarash          #+#    #+#             */
/*   Updated: 2019/09/24 15:35:07 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*sc;

	i = 0;
	if (!dest && !src)
		return (NULL);
	res = (unsigned char*)dest;
	sc = (unsigned char*)src;
	if (sc < res)
	{
		while (n-- > 0)
			res[n] = sc[n];
	}
	else
	{
		while (n > 0)
		{
			res[i] = sc[i];
			i++;
			n--;
		}
	}
	return (res);
}
