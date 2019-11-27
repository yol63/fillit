/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:11:29 by romarash          #+#    #+#             */
/*   Updated: 2019/10/23 14:26:36 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoine(char *s1, char *s2)
{
	size_t	n;
	size_t	i;
	char	*res;

	n = 0;
	i = 0;
	if (!s1 || !s2 || !(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
		res[n++] = s1[i++];
	i = 0;
	while (s2[i])
		res[n++] = s2[i++];
	res[n] = '\0';
	free(s1);
	s1 = NULL;
	return (res);
}

char	*ft_copy(char *buf, size_t *start)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!buf || !start || !(res = ft_strnew(ft_strlen(buf) + 1)))
		return (NULL);
	while (buf[i] != '\0' && buf[i] != CHAR_SEP)
	{
		res[i] = buf[i];
		i++;
	}
	res[i] = '\0';
	*start = i + 1;
	return (res);
}

int		ft_read(int fd, char *buf)
{
	int		ret;
	size_t	i;

	i = 0;
	ret = 0;
	if (!buf)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	while (buf[i])
	{
		if (buf[i] == CHAR_SEP)
			return (1);
		i++;
	}
	if (ret == BUFF_SIZE)
		return (5);
	else
		return (0);
}

void	ft_buffer(char *buff, size_t *start)
{
	size_t i;
	size_t j;

	i = 0;
	j = *start;
	if (!buff || !start)
		return ;
	while (buff[j])
	{
		buff[i] = buff[j];
		i++;
		j++;
	}
	buff[i] = '\0';
	*start = j;
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*buff[256];
	int			ret;
	size_t		start;

	start = 0;
	ret = 5;
	if (fd < 0 || fd >= 256 || !line)
		return (-1);
	if (!(buff[fd]))
		buff[fd] = ft_strnew(BUFF_SIZE);
	while (ret == 5)
	{
		ret = ft_read(fd, buf);
		if (ret == -1)
			return (-1);
		buff[fd] = ft_strjoine(buff[fd], buf);
	}
	if (!(buff[fd]))
		return (-1);
	*line = ft_copy(buff[fd], &start);
	if (buff[fd][0] == '\0' && ret == 0)
		return (0);
	ft_buffer(buff[fd], &start);
	return (1);
}
