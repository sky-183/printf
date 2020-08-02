/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 12:38:56 by vflander          #+#    #+#             */
/*   Updated: 2020/07/13 14:03:26 by vflander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		gnl_first_read(int fd, char **line, char **buffer)
{
	ssize_t		bytes_read;
	char		temp_buffer[BUFFER_SIZE + 1];

	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (0 == bytes_read)
	{
		if (NULL == (*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	else if (bytes_read > 0)
	{
		temp_buffer[bytes_read] = '\0';
		if (NULL == (*buffer = ft_strdup(temp_buffer)))
			return (-1);
	}
	return (1);
}

static int		gnl_read_until_n(int fd, char **line, char **buffer)
{
	ssize_t		bytes_read;
	char		temp_buffer[BUFFER_SIZE + 1];
	char		*temp_to_free;

	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	temp_buffer[bytes_read] = '\0';
	if (0 == bytes_read)
	{
		if (NULL == (*line = ft_strdup(*buffer)))
			return (-1);
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	temp_to_free = *buffer;
	if (NULL == (*buffer = ft_strjoin(*buffer, temp_buffer)))
		return (-1);
	free(temp_to_free);
	return (1);
}

static int		gnl_write_to_line(char **line, char **buffer, char *position_n)
{
	char		*temp_to_free;

	if (NULL == (*line = ft_strdup(*buffer)))
		return (-1);
	temp_to_free = *buffer;
	if (NULL == (*buffer = ft_strdup(position_n + 1)))
		return (-1);
	free(temp_to_free);
	return (1);
}

/*
**	get_next_line
**	Returns a next line from a given file descriptor in a **line
**	Function's return value:
**	 1 : a line has been read
**	 0 : EOF has been reached
**	-1 : an error happened
**	TODO: make read-like return after moulinette evaluation for better use
**
**	Could use heap memory (malloc) for 'temp_buffer' if we need really big
**	buffer size for some reason. Now we dont. And it brings more cleaning.
**
**	Could keep length of current 'buffer[fd]' for searching (ft_strchr) not
**	from the start each time, but from the newly appended block only. Could
**	improve performance, but only for cases with low buffer + long strings.
**	This means it will be static struct with both buffer and len for each 'fd'.
**
**	defines:
**	BUFFER_SIZE - number of byter to read at a time, defined on compilation
**	(-D BUFFER_SIZE=32). Default = 32 (if none was given).
**	MAX_OPEN_FD - max number of opened files for which to keep buffers.
**	Default = 10 000.
*/

int				get_next_line(int fd, char **line)
{
	static char	*buffer[MAX_OPEN_FD];
	char		temp_buffer[1];
	char		*position_n;
	int			return_value;

	if (BUFFER_SIZE < 1 || fd < 0 || NULL == line || fd >= MAX_OPEN_FD ||\
		read(fd, temp_buffer, 0) == -1 || (BUFFER_SIZE + 1) < BUFFER_SIZE)
		return (-1);
	*line = NULL;
	if (buffer[fd] == NULL)
		if ((return_value = gnl_first_read(fd, &(*line), &(buffer[fd]))) < 1)
			return (return_value);
	position_n = ft_strchr(buffer[fd], '\n');
	while (NULL == position_n)
	{
		if ((return_value = gnl_read_until_n(fd, &(*line), &(buffer[fd]))) < 1)
			return (return_value);
		position_n = ft_strchr(buffer[fd], '\n');
	}
	*position_n = '\0';
	if ((return_value = gnl_write_to_line(&(*line), &(buffer[fd]),\
										position_n)) < 1)
		return (return_value);
	return (1);
}
