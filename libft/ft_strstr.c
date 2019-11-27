/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:11:49 by romarash          #+#    #+#             */
/*   Updated: 2019/09/22 16:15:08 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	j = 0;
	n = 0;
	if (!str1[i] && !str2[j])
		return ((char*)str1);
	while (str1[i])
	{
		while (str1[i] == str2[j] && str2[j])
		{
			i++;
			j++;
		}
		if (str2[j] == '\0')
			return ((char*)&str1[i - ft_strlen(str2)]);
		j = 0;
		n++;
		i = n;
	}
	return (NULL);
}
