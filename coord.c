/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:27:23 by romarash          #+#    #+#             */
/*   Updated: 2019/12/07 15:55:03 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_minx(int *coord)
{
	int i;
	int res;

	i = 0;
	res = 4;
	while (i < 8)
	{
		if (coord[i] < res)
			res = coord[i];
		i = i + 2;
	}
	return (res);
}

int		ft_miny(int *coord)
{
	int i;
	int res;

	i = 1;
	res = 4;
	while (i < 8)
	{
		if (coord[i] < res)
			res = coord[i];
		i = i + 2;
	}
	return (res);
}

void	ft_coord_to_null(t_tetraminka *start)
{
	int i;
	int j;
	int minx;
	int miny;

	i = 0;
	j = 1;
	minx = ft_minx(start->coord);
	miny = ft_miny(start->coord);
	while (i < 8)
	{
		start->coord[i] = start->coord[i] - minx;
		i = i + 2;
	}
	while (j < 8)
	{
		start->coord[j] = start->coord[j] - miny;
		j = j + 2;
	}
}

int		*ft_find_start_coord(char **map, t_tetraminka *tetra, int razmer)
{
	int i;
	int j;
	int *start_coord;

	j = 0;
	start_coord = (int*)malloc(sizeof(int) * 2);
	start_coord[0] = razmer;
	start_coord[1] = razmer;
	while (j < razmer)
	{
		i = 0;
		while (i < razmer)
		{
			if (map[j][i] == tetra->c)
			{
				if (start_coord[0] > i)
					start_coord[0] = i;
				if (start_coord[1] > j)
					start_coord[1] = j;
			}
			i++;
		}
		j++;
	}
	return (start_coord);
}

int		ft_put_1tetraminka(t_tetraminka *start, char **map, int x0, int y0)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 8)
	{
		x = start->coord[i];
		y = start->coord[i + 1];
		if ((map[y + y0] != NULL) && (map[y + y0][x + x0] == '.'))
			i = i + 2;
		else
			return (0);
	}
	i = 0;
	while (i < 8)
	{
		x = start->coord[i];
		y = start->coord[i + 1];
		map[y + y0][x + x0] = start->c;
		i = i + 2;
	}
	return (1);
}
