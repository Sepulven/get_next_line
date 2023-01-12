/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:41:24 by asepulve          #+#    #+#             */
/*   Updated: 2022/11/28 16:02:50 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	size_t			i;

	i = 0;
	line = NULL;
	if (read(fd, 0, 0) || fd >= FOPEN_MAX || fd < 0)
	{
		while (fd >= 0 && fd <= FOPEN_MAX && i < BUFFER_SIZE)
			buf[fd][i++] = 0;
		return (NULL);
	}
	if (buf[fd][0] == 0)
		buf[fd][read(fd, buf[fd], BUFFER_SIZE)] = 0;
	while (buf[fd][0])
	{
		line = ft_strjoin(line, buf[fd]);
		if (!line)
			return (NULL);
		if (checkeol(buf[fd]))
			return (orgbuf(buf[fd], line));
		buf[fd][read(fd, buf[fd], BUFFER_SIZE)] = 0;
	}
	return (line);
}
