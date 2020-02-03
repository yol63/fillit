/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:20:26 by romarash          #+#    #+#             */
/*   Updated: 2020/01/30 18:27:29 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H
# define BUFF_SIZEE 20

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"

void					check_file(char *line);
void					check_figure(char *line);
int						setup(char **argv);
void					w_count(char *line, int *w_arr);
void					h_count(char *line, int *h_arr);
int						setup(char **argv);
void					ft_error(int error);
int						creation(int fd);
void					ft_checkfig(char *line, int *j, int *t);
void					touch_validate(int touch, char *line);
int						ft_return(int fd, char **buf, int r);

#endif
