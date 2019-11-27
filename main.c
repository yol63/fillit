/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 21:41:30 by romarash          #+#    #+#             */
/*   Updated: 2019/11/26 21:41:33 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <unistd.h>
#include <fcntl.h>
#include <get_next_line.h>
# include <fillit.h>

void    ft_lstiters(t_tetraminka *list, void (*f)(t_tetraminka *elem))
{
    t_tetraminka *newlist;
    
    newlist = NULL;
    if (!list || !f)
        return ;
    newlist = list;
    while (newlist)
    {
        ft_putstr("tetraminka\n");
        f(newlist);
        newlist = newlist->next;
    }
}

void ft_write(t_tetraminka *start)
{
    int res;
    int i = 0;
    
    while (i < 8) {
        
        res = start->coord[i];
        ft_putnbr(res);
        ft_putchar(start->c);
        ft_putchar('\n');
        i++;
    }
}


int    main(int argc, char **argv)
{
    int fd;
    char *line;
    int i = 0;
    int j = 0;
    int k = 0;
    int res;
    t_tetraminka *tetramino;
    t_tetraminka *new_tetramino;
    t_tetraminka *start;
    
    
    if (argc != 2  /* || ft_validation(argv[1] == 0)*/)
        ft_putstr("ERROR\n");
    
    fd = open(argv[1], O_RDONLY);
    tetramino = malloc(sizeof(t_tetraminka));
    start = tetramino;
    tetramino->coord = (int*)malloc (sizeof(int) * 8);
    tetramino->c = 'A';
    tetramino->next = NULL;
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
            new_tetramino = malloc(sizeof(t_tetraminka));
            new_tetramino->coord = (int*)malloc (sizeof(int) * 8);
            new_tetramino->next = NULL;
            new_tetramino->c = tetramino->c + 1;
            tetramino->next = new_tetramino;
            tetramino = new_tetramino;
        }
        free(line);
        line = NULL;
    }
    i = 0;
    ft_lstiters(start, ft_write);
    return (0);
}
