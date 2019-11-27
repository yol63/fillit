/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:28:28 by romarash          #+#    #+#             */
/*   Updated: 2019/09/30 22:36:21 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *app)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	while (dest[i])
		i++;
	while (app[n])
	{
		dest[i] = app[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (dest);
}
