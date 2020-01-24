/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_h_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:26:45 by romarash          #+#    #+#             */
/*   Updated: 2020/01/24 16:38:10 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "fillit.h"

int		ft_count_tetra(t_tetraminka *list)
{
	int				i;
	t_tetraminka	*newlist;

	i = 0;
	if (!list)
		return (0);
	newlist = list;
	while (newlist->next)
	{
		newlist = newlist->next;
		i++;
	}
	return (i);
}

int		setup(char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if ((fd <= -1))
		return (-1);
	if (creation(fd) == 0)
		return (0);
	close(fd);
	return (1);
}

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_putstr("usage: ./fillit test.txt\n");
		exit(1);
	}
	if (error == 2)
	{
		ft_putstr("error\n");
		exit(1);
	}
}
