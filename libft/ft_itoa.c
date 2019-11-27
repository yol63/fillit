/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:35:56 by romarash          #+#    #+#             */
/*   Updated: 2019/09/24 13:34:11 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_rev(char *s)
{
	size_t	i;
	size_t	n;
	char	*res;

	i = 0;
	n = ft_strlen(s);
	if (!(res = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	res[n] = '\0';
	while (i < n)
	{
		res[i] = s[n - 1];
		res[n - 1] = s[i];
		i++;
		n--;
	}
	return (res);
}

static size_t	ft_action(char *s, long int n)
{
	size_t i;

	i = 0;
	while (n >= 1)
	{
		s[i] = (n % 10) + '0';
		i++;
		n = n / 10;
	}
	return (i);
}

static char		*ft_checker(int n)
{
	char *res;

	if (!(res = (char*)malloc(sizeof(char) * n)))
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	long int	nb;
	size_t		i;
	int			flag;
	char		*res;

	i = 0;
	flag = 0;
	nb = (long int)n;
	res = NULL;
	if (nb == 0)
		return (ft_checker(2));
	if (!(res = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	if (nb < 0)
	{
		nb = (-1) * nb;
		flag = 1;
	}
	i = ft_action(res, nb);
	if (flag == 1)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_rev(res));
}
