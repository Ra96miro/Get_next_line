/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramiro- <gramiro-@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:33:07 by gramiro-          #+#    #+#             */
/*   Updated: 2022/04/04 19:34:55 by gramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	a;

	if (!str)
		return (0);
	a = 0;
	while (*str)
	{
		str++;
		a++;
	}
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	temp;

	temp = c;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == temp)
			return ((char *) s);
		s++;
	}
	if (*s == temp)
		return ((char *) s);
	return (0);
}
