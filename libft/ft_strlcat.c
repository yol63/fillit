/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:58:38 by romarash          #+#    #+#             */
/*   Updated: 2019/09/22 18:04:55 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t n;
	size_t k;

	i = 0;
	n = 0;
	k = ft_strlen(dest);
	if (size < k + 1)
		return (size + ft_strlen(src));
	while (dest[i])
		i++;
	while (src[n] && i < size - 1)
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (k + ft_strlen(src));
}
