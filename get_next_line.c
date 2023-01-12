/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:44:36 by asepulve          #+#    #+#             */
/*   Updated: 2022/11/29 13:29:24 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		buf[BUFFER_SIZE + 1];
	size_t			i;

	i = 0;
	line = NULL;
	if (read(fd, 0, 0) || BUFFER_SIZE < 1)
	{
		while (i < BUFFER_SIZE)
			buf[i++] = 0;
		return (NULL);
	}
	if (!buf[0])
		buf[read(fd, buf, BUFFER_SIZE)] = 0;
	while (buf[0])
	{
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (checkeol(buf))
			return (orgbuf(buf, line));
		buf[read(fd, buf, BUFFER_SIZE)] = 0;
	}
	return (line);
}
