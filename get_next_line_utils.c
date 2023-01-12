/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:10:56 by asepulve          #+#    #+#             */
/*   Updated: 2022/11/28 15:54:29 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = (char)s1[j++];
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		str[i++] = (char)s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	if (s1)
		free((void *)s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	return (count + (str[count] == '\n'));
}

char	*orgbuf(char *buf, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	i += (buf[i] == '\n');
	j = 0;
	while (i < BUFFER_SIZE)
		buf[j++] = buf[i++];
	buf[j++] = 0;
	return (line);
}

int	checkeol(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
		if (buf[i++] == '\n')
			return (1);
	return (0);
}
