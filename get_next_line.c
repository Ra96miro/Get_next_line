/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 03:25:58 by gramiro-          #+#    #+#             */
/*   Updated: 2022/04/01 12:45:29 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_save(char *buff)
{
	int		x;
	int		y;
	char	*rest;

	x = 0;
	y = 0;
	while (buff[x] != '\n' && buff[x])
		x++;
	rest = (char *)malloc(sizeof(char) * (ft_strlen(buff) - x + 1));
	if (!rest)
		return (0);
	x++;
	while (buff[x])
	{
		rest[y] = buff[x];
		x++;
		y++;
	}
	rest[y] = '\0';
	free(buff);
	return (rest);
}

char	*get_line(char *buff)
{
	int		x;
	char	*s;

	x = 0;
	if (!buff)
		return (0);
	while (buff[x] != '\n' && buff[x])
		x++;
	s = (char *)malloc(sizeof(char) * (x + 2));
	if (!s)
		return (0);
	x = -1;
	while (buff[++x] != '\n' && buff[x])
		s[x] = buff[x];
	if (buff[x] == '\n')
	{
		s[x] = '\n';
		s[x + 1] = '\0';
	}
	else
		s[x] = '\0';
	return (s);
}

char	*get_read_file(int fd, char *file)
{
	char	*buff;
	int		size;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	size = 1;
	while (!ft_strchr(buff, '\n') && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
			return (0);
		buff[size] = '\0';
		file = ft_strjoin(file, buff);
	}
	free(buff);
	return (file);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = get_read_file(fd, save);
	line = get_line(save);
	save = get_save(save);
	return (line);
}

// int main()
// {
// 	int	fd;

// 	fd = open("prova.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }