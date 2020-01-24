/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:31:36 by romarash          #+#    #+#             */
/*   Updated: 2020/01/24 16:32:26 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_create_new_tetramino(int *k, t_tetraminka **tetra,
		char **line, int fd)
{
	t_tetraminka *new_tetramino;

	*k = 0;
	new_tetramino = ft_lstnews();
	new_tetramino->c = (*tetra)->c + 1;
	(*tetra)->next = new_tetramino;
	new_tetramino->last = *tetra;
	*tetra = new_tetramino;
	free(*line);
	*line = NULL;
	get_next_line(fd, line);
}

void	ft_save_coord(int *i, int *j, int *k, t_tetraminka *tetramino)
{
	tetramino->coord[*k] = *i + 1;
	tetramino->coord[*k + 1] = *j + 1;
	*k = *k + 2;
}

void	ft_free_line(char *line)
{
	free(line);
	line = NULL;
}

void	ft_save_tetramino(int fd, t_tetraminka *tetra)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == '#')
				ft_save_coord(&i, &j, &k, tetra);
			i++;
		}
		j++;
		if (j == 4)
		{
			j = 0;
			ft_create_new_tetramino(&k, &tetra, &line, fd);
		}
		ft_free_line(line);
	}
	ft_free_line(line);
}

int		main(int argc, char **argv)
{
	int				fd;
	t_tetraminka	*tetra;
	t_tetraminka	*start;
	char			**map;

	if (argc != 2)
		ft_error(1);
	if (setup(argv) <= 0)
		ft_error(2);
	fd = open(argv[1], O_RDONLY);
	tetra = ft_lstnews();
	start = tetra;
	tetra->c = 'A';
	ft_save_tetramino(fd, tetra);
	if (ft_count_tetra(start) > 26)
		ft_error(2);
	ft_lstiters(start, ft_coord_to_null);
	map = ft_putt(start, 2);
	ft_write_arr(map);
	ft_lstdels(&start);
	ft_free_arr(map);
	close(fd);
	return (0);
}
