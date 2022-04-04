/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 03:25:58 by gramiro-          #+#    #+#             */
/*   Updated: 2022/04/04 19:29:58 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	get_free(char *buff, char *file)
{
	free(file);
	free(buff);
}

char	*get_save(char *save)
{
	int		x;
	int		y;
	char	*rest;

	x = 0;
	y = 0;
	while (save[x] != '\n' && save[x])
		x++;
	if (!save[x])
	{
		free(save);
		return (0);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(save) - x + 1));
	if (!rest)
		return (0);
	x++;
	while (save[x])
		rest[y++] = save[x++];
	rest[y] = '\0';
	free(save);
	return (rest);
}

char	*get_line(char *save)
{
	int		x;
	char	*s;

	x = 0;
	if (!save)
		return (0);
	while (save[x] != '\n' && save[x])
		x++;
	s = (char *)malloc(sizeof(char) * (x + 2));
	if (!s)
		return (0);
	x = -1;
	while (save[++x] != '\n' && save[x])
		s[x] = save[x];
	if (save[x] == '\n')
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
	while (!ft_strchr(file, '\n') && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			return (0);
		}
		buff[size] = '\0';
		file = ft_strjoin(file, buff);
	}
	if (ft_strlen(file) <= 0)
	{
		get_free(buff, file);
		return (0);
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
	if (!save)
		return (0);
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