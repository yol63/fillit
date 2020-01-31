/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_h_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:26:45 by romarash          #+#    #+#             */
/*   Updated: 2020/01/30 18:34:34 by romarash         ###   ########.fr       */
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
		ft_putstr("usage: fillit source_file\n");
		exit(1);
	}
	if (error == 2)
	{
		ft_putstr("error\n");
		exit(1);
	}
}

int		ft_return(int fd, char **buf, int r)
{
	free(*buf);
	buf = NULL;
	close(fd);
	return (r);
}

int		check_lines(char *input)
{
	int		fd;
	char	*buf;
	int		i;
	int		count;

	fd = open(input, O_RDONLY);
	i = 1;
	count = 0;
	while (get_next_line(fd, &buf))
	{
		if (i % 5 != 0 && (ft_strlen(buf) != 4))
			return (ft_return(fd, &buf, 0));
		if ((i % 5) == 0)
			count = 0;
		else
			count++;
		if (i % 5 == 0 && (ft_strlen(buf) != 0))
			return (ft_return(fd, &buf, 0));
		i++;
		free(buf);
	}
	if (count != 4)
		return (ft_return(fd, &buf, 0));
	return (ft_return(fd, &buf, 1));
}
