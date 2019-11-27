/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:54:12 by romarash          #+#    #+#             */
/*   Updated: 2019/09/25 16:26:00 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	int		j;

	i = ft_strlen(str);
	j = i + 1;
	while (j >= 1)
	{
		if (str[i] == (const char)ch)
			return ((char*)&str[i]);
		i--;
		j--;
	}
	return (NULL);
}
