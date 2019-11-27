/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:47:19 by romarash          #+#    #+#             */
/*   Updated: 2019/11/26 18:55:02 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft/libft.h"
# include "get_next_line.h"

typedef struct	s_tetraminka
{
	int					*coord;
	char				c;
	struct s_tetraminka	*next;
}				t_tetraminka;


#endif
