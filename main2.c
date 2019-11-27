/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:31:36 by romarash          #+#    #+#             */
/*   Updated: 2019/11/26 18:32:42 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <get_next_line.h>
# include <fillit.h>

void	ft_lstiters(t_tetraminka *list, void (*f)(t_tetraminka *elem))
{
    t_tetraminka *newlist;

    if (!list || !f)
        return ;
    newlist = list;
    while (newlist->next)
    {
        f(newlist);
        newlist = newlist->next;
    }
}

void ft_lstdels(t_tetraminka **alst)
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

t_tetraminka    *ft_lstnews()
{
    t_tetraminka    *newlist;

    if(!(newlist = malloc(sizeof(t_tetraminka))))
        return (NULL);
    if(!(newlist->coord = (int*)malloc(sizeof(int) * 8)))
    {
        free(newlist);
        return (NULL);
    }
    newlist->next = NULL;
    return(newlist);
}

void ft_write(t_tetraminka *start)
{
    int res;
    int i = 0;

    ft_putstr("tetraminka\n");
    while (i < 8)
    {
        res = start->coord[i];
        ft_putnbr(res);
        ft_putchar(start->c);
        ft_putchar('\n');
        i++;
    }
}

int ft_minx(int *coord)
{
    int i = 0;
    int res = 4;
    while(i < 8)
    {
        if(coord[i] < res)
            res = coord[i];
        i = i + 2;
    }
    return(res);
}

int ft_miny(int *coord)
{
    int i = 1;
    int res = 4;
    while(i < 8)
    {
        if(coord[i] < res)
            res = coord[i];
        i = i + 2;
    }
    return(res);
}

void    ft_coord_to_null (t_tetraminka *start)
{
    int i = 0;
    int j = 1;
    int minx;
    int miny;

    minx = ft_minx(start->coord);
    miny = ft_miny(start->coord);
    while(i < 8)
    {
        start->coord[i] = start->coord[i] - minx;
        i = i + 2;
    }
    while(j < 8)
    {
        start->coord[j] = start->coord[j] - miny;
        j = j + 2;
    }
}

char    **ft_create_map(int x)
{
    char    **map;
    int i;
    int j;

    i = 0;
    j = 0;
    if(!(map = (char**)malloc(sizeof(char*) * (x + 1))))
        return (NULL);
    while(i < x)
    {
        j = 0;
        if(!(map[i] = (char*)malloc(sizeof(char) * (x + 1))))
            return (NULL);
        while (j < x)
        {
            map[i][j] = '.';
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
    map[i] = NULL;
    return(map);
}

void	ft_write_arr(char **res)
{
    size_t i;

    i = 0;
    while (res[i])
    {
        ft_putstr(res[i]);
        ft_putchar('\n');
        i++;
    }
    ft_putchar('\n');
}

int    ft_put_1tetraminka(t_tetraminka *start, char **map,int x0, int y0)
{
    int i;
    int x;
    int y;

    i = 0;
    while(i < 8)
    {
        x = start->coord[i];
        y = start->coord[i + 1];
        if ((map[y + y0] != NULL) && (map[y + y0][x + x0] == '.'))
            i = i + 2;
        else
            return (0);
    }
    i = 0;
    while(i < 8)
    {
        x = start->coord[i];
        y = start->coord[i + 1];
        map[y + y0][x + x0] = start->c;
        i = i + 2;
    }
    return (1);
}

int    ft_put(t_tetraminka *start, int razmer)
{
    int x0 = 0;
    int y0 = 0;
    char    **map;

    map = ft_create_map(razmer);
    while (y0 + 2 <= razmer)
    {
        x0 = 0;
        while(x0 + 2 <= razmer)
        {
            if (ft_put_1tetraminka(start,map,x0, y0) == 1)
            {
                ft_write_arr(map);
                return (1);
            }
            x0++;
        }
        y0++;
    }
    return (0);
}

void    ft_putt(t_tetraminka *start)
{
    int     razmer = 2;
    int     check = 0;
    char    **map;

    while(start->next)
    {
        while (check != 1)
        {
            check = ft_put(start, razmer);
            if (check==0)
                razmer++;
        }
        razmer = 2;
        check = 0;
        start = start->next;
    }
}

int	main(int argc, char **argv)
{
    int fd;
    char *line;
    int i = 0;
    int j = 0;
    int k = 0;
    t_tetraminka *tetramino;
    t_tetraminka *new_tetramino;
    t_tetraminka *start;
    char** map;

    if (argc != 2  /* || ft_validation(argv[1] == 0)*/)
        ft_putstr("ERROR\n");

    fd = open(argv[1], O_RDONLY);
    tetramino = ft_lstnews();
    start = tetramino;
    tetramino->c = 'A';
    while (get_next_line(fd, &line) == 1)
    {
        i = 0;
        while (line[i])
        {
            if (line[i] == '#')
            {
                tetramino->coord[k] = i + 1;
                tetramino->coord[k + 1] = j + 1;
                k = k + 2;
            }
            i++;
        }
        j++;
        if (j == 5)
        {
            j = 0;
            k = 0;
            new_tetramino = ft_lstnews();
            new_tetramino->c = tetramino->c + 1;
            tetramino->next = new_tetramino;
            tetramino = new_tetramino;
        }
        free(line);
        line = NULL;
    }
    ft_lstiters(start, ft_write);
    ft_putchar('\n');
    ft_lstiters(start,ft_coord_to_null);
    ft_lstiters(start, ft_write);
    ft_putchar('\n');
    map = ft_create_map(7);
    ft_putchar('\n');
    ft_write_arr(map);
    ft_putchar('\n');
    ft_put_1tetraminka(start, map,0,0);
    ft_put_1tetraminka(start->next, map,0,0);
    ft_write_arr(map);
    ft_putchar('\n');
    ft_putt(start);
    ft_lstdels(&start);
    ft_free_arr(map);
    return (0);
}