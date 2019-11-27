/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:12:27 by romarash          #+#    #+#             */
/*   Updated: 2019/09/22 20:39:36 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	k;
	unsigned char	*res;
	unsigned char	*sc;

	i = 0;
	if (!dest && !src)
		return (NULL);
	k = (unsigned char)c;
	sc = (unsigned char*)src;
	res = (unsigned char*)dest;
	while (i < n)
	{
		res[i] = sc[i];
		if (sc[i] == k)
			return (&res[i + 1]);
		i++;
	}
	return (NULL);
}
