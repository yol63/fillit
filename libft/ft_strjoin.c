/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:14:06 by romarash          #+#    #+#             */
/*   Updated: 2019/09/12 13:23:34 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	i;
	char	*res;

	n = 0;
	i = 0;
	if (!s1 || !s2 || !(res = (char*)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		res[n] = s1[i];
		n++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[n] = s2[i];
		i++;
		n++;
	}
	res[n] = '\0';
	return (res);
}
