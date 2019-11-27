/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:37:12 by romarash          #+#    #+#             */
/*   Updated: 2019/09/24 16:23:17 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char *s)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	n;
	char	*res;

	i = 0;
	n = 0;
	if (!s || !(res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		res[0] = '\0';
		return (res);
	}
	while (s[i] != '\0')
		res[n++] = s[i++];
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
	{
		i--;
		n--;
	}
	res[n] = '\0';
	return (ft_copy(res));
}
