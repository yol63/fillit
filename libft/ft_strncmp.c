/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:58:04 by romarash          #+#    #+#             */
/*   Updated: 2019/09/22 19:17:43 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	if (n == 0)
		return (0);
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
