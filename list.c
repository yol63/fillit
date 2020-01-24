/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:58:23 by romarash          #+#    #+#             */
/*   Updated: 2020/01/24 16:14:04 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_lstiters(t_tetraminka *list, void (*f)(t_tetraminka *elem))
{
	t_tetraminka	*newlist;

	if (!list || !f)
		return ;
	newlist = list;
	while (newlist->next)
	{
		f(newlist);
		newlist = newlist->next;
	}
}

void			ft_lstdels(t_tetraminka **alst)
{
	t_tetraminka	*list;

	if (alst)
	{
		while (*alst)
		{
			list = (*alst)->next;
			free((*alst)->coord);
			free(*alst);
			*alst = list;
		}
		free(*alst);
		*alst = NULL;
	}
}

t_tetraminka	*ft_lstnews(void)
{
	t_tetraminka	*newlist;

	if (!(newlist = malloc(sizeof(t_tetraminka))))
		return (NULL);
	if (!(newlist->coord = (int*)malloc(sizeof(int) * 8)))
	{
		free(newlist);
		return (NULL);
	}
	newlist->next = NULL;
	newlist->last = NULL;
	return (newlist);
}

char			**ft_create_map(int x)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	while (i < x)
	{
		j = 0;
		if (!(map[i] = (char*)malloc(sizeof(char) * (x + 1))))
		{
			ft_free_arr(map);
			return (NULL);
		}
		while (j < x)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void			ft_write_arr(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		ft_putstr(res[i]);
		ft_putchar('\n');
		i++;
	}
}
