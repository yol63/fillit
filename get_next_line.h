/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:42:36 by romarash          #+#    #+#             */
/*   Updated: 2019/10/16 22:30:07 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 150
# define CHAR_SEP '\n'

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
