/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:53:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/11/22 13:28:00 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_newline(char *s)
{
	if (s)
	{
		while (*s)
		{
			if (*s == '\n')
				return (1);
			s++;
		}
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		readed;

	line = NULL;
	readed = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (readed && !ft_newline(line))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), NULL);
		if (buffer[0] == '\n')
			return (free(buffer), line);
		buffer[readed] = 0;
		line = ft_strjoin(line, buffer);
	}
	return (free(buffer), line);
}
