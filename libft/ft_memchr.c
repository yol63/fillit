/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:45:36 by romarash          #+#    #+#             */
/*   Updated: 2019/09/22 18:31:26 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	res = (unsigned char*)arr;
	while (i < n)
	{
		if (res[i] == cc)
			return (&res[i]);
		i++;
	}
	return (NULL);
}
