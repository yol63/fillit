/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:55:45 by romarash          #+#    #+#             */
/*   Updated: 2020/01/24 18:40:43 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_dostat(char **map, int razmer, t_tetraminka *tetra)
{
	int i;
	int j;

	j = 0;
	while (j < razmer)
	{
		i = 0;
		while (i < razmer)
		{
			if (map[i][j] == tetra->c)
				map[i][j] = '.';
			i++;
		}
		j++;
	}
}

int				ft_move(t_tetraminka *tetra, int razmer, char **map)
{
	int x0;
	int y0;
	int *start_coord;

	start_coord = ft_find_start_coord(map, tetra, razmer);
	x0 = start_coord[0];
	y0 = start_coord[1];
	free(start_coord);
	ft_dostat(map, razmer, tetra);
	while (y0 < razmer)
	{
		if (x0 + 1 < razmer)
			x0++;
		else if (y0 < razmer)
		{
			y0++;
			x0 = 0;
		}
		if (ft_put_1tetraminka(tetra, map, x0, y0) == 1)
			return (1);
	}
	return (0);
}

t_tetraminka	*ft_check(t_tetraminka *tetra, int razmer, char **map)
{
	int check;

	check = 0;
	tetra = tetra->last;
	check = ft_move(tetra, razmer, map);
	if (check == 1)
		tetra = tetra->next;
	else
	{
		while (check == 0 && tetra->last)
		{
			tetra = tetra->last;
			check = ft_move(tetra, razmer, map);
		}
		if (check == 1)
			tetra = tetra->next;
	}
	return (tetra);
}

int				ft_put(t_tetraminka *start, int razmer, char **map)
{
	int x0;
	int y0;

	y0 = 0;
	while (y0 + 1 <= razmer)
	{
		x0 = 0;
		while (x0 + 1 <= razmer)
		{
			if (ft_put_1tetraminka(start, map, x0, y0) == 1)
				return (1);
			x0++;
		}
		y0++;
	}
	return (0);
}

char			**ft_putt(t_tetraminka *start, int razmer)
{
	int				check;
	char			**map;
	t_tetraminka	*tetra;

	tetra = start;
	map = ft_create_map(razmer);
	while (tetra->next)
	{
		check = ft_put(tetra, razmer, map);
		if (check == 1)
			tetra = tetra->next;
		if (check == 0)
		{
			if (tetra->last)
				tetra = ft_check(tetra, razmer, map);
			if (!(tetra->last))
			{
				razmer++;
				ft_free_arr(map);
				map = ft_create_map(razmer);
				tetra = start;
			}
		}
	}
	return (map);
}
