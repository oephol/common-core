/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:59:24 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/15 10:10:14 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **line, char **buffer, int yes_line)
{
	if (yes_line)
	{
		free(*line);
		*line = NULL;
	}
	free(*buffer);
	*buffer = NULL;
	return (*line);
}

static size_t	ft_nl_index(char *s, size_t i, size_t len)
{
	if (!s || !len)
		return (0);
	while (i < len - 1 && s[i] != '\n')
		i++;
	return (i);
}

static int	ft_fill_buffer(int fd, t_line *line, t_buf *buf)
{
	if (buf->pos != (size_t)buf->n_read)
		return (1);
	buf->n_read = read(fd, buf->buffer, BUFFER_SIZE);
	buf->pos = 0;
	if (buf->n_read == -1)
	{
		buf->n_read = 0;
		return (-1);
	}
	if (buf->n_read == 0 && line->index == 0)
		return (0);
	if (buf->n_read == 0)
		return (2);
	return (1);
}

static char	*ft_append_toline(t_line *line, t_buf *buf)
{
	size_t	i;
	size_t	stop_index;
	char	*new_line;

	stop_index = ft_nl_index(buf->buffer, buf->pos, buf->n_read);
	if (line->index + (stop_index - buf->pos + 1) + 2 >= line->size)
	{
		while (line->index + (stop_index - buf->pos + 1) + 2 >= line->size)
			line->size += 1024;
		new_line = malloc(line->size);
		if (!new_line)
			return (ft_free(&line->buffer, &buf->buffer, 1));
		i = 0;
		while (i < line->index)
		{
			new_line[i] = line->buffer[i];
			i++;
		}
		free(line->buffer);
		line->buffer = new_line;
	}
	while (buf->pos <= stop_index)
		line->buffer[line->index++] = buf->buffer[buf->pos++];
	line->buffer[line->index] = '\0';
	return (line->buffer);
}

char	*ft_read_line(int fd, t_buf *buf)
{
	t_line	line;
	int		status;

	line.index = 0;
	line.size = 1024;
	line.buffer = malloc(line.size);
	if (!line.buffer)
		return (ft_free(&line.buffer, &buf->buffer, 1));
	while (1)
	{
		status = ft_fill_buffer(fd, &line, buf);
		if (status == -1)
			return (ft_free(&line.buffer, &buf->buffer, 1));
		if (status == 0)
			return (ft_free(&line.buffer, &buf->buffer, 1));
		if (status == 2)
			return (ft_free(&line.buffer, &buf->buffer, 0));
		line.buffer = ft_append_toline(&line, buf);
		if (!line.buffer)
			return (ft_free(&line.buffer, &buf->buffer, 0));
		if (buf->pos > 0 && buf->buffer[buf->pos - 1] == '\n')
			return (line.buffer);
	}
}
