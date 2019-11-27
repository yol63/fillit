/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:32:19 by romarash          #+#    #+#             */
/*   Updated: 2019/09/22 16:06:39 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (dest[i])
		i++;
	while (app[k] && k < n)
	{
		dest[i] = app[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
