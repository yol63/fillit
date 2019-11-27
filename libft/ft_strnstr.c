/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:40:54 by romarash          #+#    #+#             */
/*   Updated: 2019/09/22 20:12:03 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	if (str2[0] == '\0')
		return ((char*)str1);
	if (n == 0)
		return (NULL);
	while (str1[i])
	{
		while (str1[i] == str2[j] && str2[j] && i < n)
		{
			i++;
			j++;
		}
		if (str2[j] == '\0')
			return ((char*)&str1[i - ft_strlen(str2)]);
		j = 0;
		k++;
		i = k;
	}
	return (NULL);
}
