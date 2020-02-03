/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:29:27 by romarash          #+#    #+#             */
/*   Updated: 2020/02/01 19:48:13 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

void		check_file(char *line)
{
	int i;
	int hcount;
	int ncount;
	int dcount;

	i = 0;
	hcount = 0;
	ncount = 0;
	dcount = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '#')
			hcount++;
		else if (line[i] == '.')
			dcount++;
		else if (line[i] == '\n')
			ncount++;
		i++;
	}
	if (hcount != 4 || dcount != 12 || ncount != 4 || line[0] == '\n')
	{
		write(1, "error\n", 6);
		exit(1);
	}
	return ;
}

void		touch_validate(int touch, char *line)
{
	if (touch == 6 || touch == 8)
		return ;
	else
	{
		write(1, "error\n", 6);
		free(line);
		exit(1);
	}
}

void		check_figure(char *line)
{
	int touch;
	int hcount;
	int i;

	touch = 0;
	hcount = 0;
	i = 0;
	while (hcount < 4)
	{
		while (line[i] != '#')
			i++;
		if ((i + 1 >= 0) && (i + 1 <= 20) && (line[i + 1] == '#'))
			touch++;
		if ((i - 1 >= 0) && (i - 1 <= 20) && (line[i - 1] == '#'))
			touch++;
		if ((i + 5 >= 0) && (i + 5 <= 20) && (line[i + 5] == '#'))
			touch++;
		if ((i - 5 >= 0) && (i - 5 <= 20) && (line[i - 5] == '#'))
			touch++;
		hcount++;
		i++;
	}
	touch_validate(touch, line);
}

void		ft_line(char **line)
{
	check_file(*line);
	check_figure(*line);
	free(*line);
	*line = NULL;
	return ;
}

int			creation(int fd)
{
	int			rd;
	char		*line;

	if (!(line = ft_strnew(BUFF_SIZEE)))
		ft_error(2);
	if ((rd = read(fd, line, BUFF_SIZEE)) == 0)
		return (ft_return(fd, &line, 0));
	ft_line(&line);
	while (rd == 20)
	{
		if (!(line = ft_strnew(1)))
			ft_error(2);
		if ((rd = read(fd, line, 1)) < 0)
			ft_error(2);
		if (rd == 0)
			return (ft_return(fd, &line, 1));
		free(line);
		if (!(line = ft_strnew(BUFF_SIZEE)))
			ft_error(2);
		if ((rd = read(fd, line, BUFF_SIZEE)) < 0)
			ft_error(2);
		ft_line(&line);
	}
	return (0);
}
