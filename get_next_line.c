/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aporras- <aporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:40:52 by aporras-          #+#    #+#             */
/*   Updated: 2024/09/06 16:56:10 by aporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	rest = malloc((ft_strlen(buffer) - i + 1) * (sizeof(char)));
	if (!rest)
		return (NULL);
	j = 0;
	while (buffer[i++])
	{
		rest[j++] = buffer[i];
	}
	rest[j] = '\0';
	return (free(buffer), rest);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != 0 && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != 0 && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_buffer(int fd, char *buffer)

{
	char	*read_line;
	size_t	bytes;
	char	*new_array;

	bytes = 1;
	read_line = malloc((BUFFER_SIZE +1) * (sizeof(char)));
	if (!read_line)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, read_line, BUFFER_SIZE);
		if ((int)bytes == -1)
		{
			free(read_line);
			return (NULL);
		}
		read_line[bytes] = '\0';
		new_array = buffer;
		buffer = ft_strjoin(buffer, read_line);
		free(new_array);
	}
	free(read_line);
	return (buffer);
}

char	*get_next_line(int fd)

{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
		if (!buffer)
			return (NULL);
	}
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = buffer_rest(buffer);
	return (line);
}
