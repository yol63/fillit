/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:31:10 by romarash          #+#    #+#             */
/*   Updated: 2019/10/01 12:57:38 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strln(char const *s, char c, size_t *k)
{
	size_t i;
	size_t n;

	i = 0;
	n = *k;
	while (s[n] && s[n] == c)
		n++;
	*k = n;
	while (s[n] && s[n] != c)
	{
		n++;
		i++;
	}
	return (i);
}

static char		*ft_create(char const *s, char c, size_t *k)
{
	size_t		n;
	size_t		l;
	size_t		i;
	char		*res;

	n = 0;
	i = 0;
	l = 0;
	l = ft_strln(s, c, k);
	if (!(res = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	n = *k;
	while (i < l)
	{
		res[i] = s[n];
		n++;
		i++;
	}
	res[i] = '\0';
	*k = n;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	n;
	size_t	k;
	char	**res;

	i = 0;
	n = 0;
	k = 0;
	if (!s)
		return (NULL);
	n = ft_count(s, c);
	if (!(res = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		res[i] = ft_create(s, c, &k);
		if (!res[i])
		{
			ft_free_arr(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
