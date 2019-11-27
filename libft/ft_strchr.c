/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:35:56 by romarash          #+#    #+#             */
/*   Updated: 2019/09/30 22:10:04 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	ch1;
	char	*res;

	i = 0;
	res = NULL;
	ch1 = (char)ch;
	if (ch == 0)
	{
		while (str[i])
			i++;
		res = (char*)&str[i];
		return (res);
	}
	while (str[i])
	{
		if (str[i] == ch1)
		{
			res = (char*)&str[i];
			return (res);
		}
		i++;
	}
	return (NULL);
}
