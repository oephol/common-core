/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:59:29 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/16 16:14:58 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_append_toline(t_line *line, t_node *node, t_node **head)
{
	size_t	i;
	size_t	stop_index;
	char	*new_line;

	stop_index = ft_nl_index(node->buf.buffer, node->buf.pos, node->buf.n_read);
	if (line->index + (stop_index - node->buf.pos + 1) + 2 >= line->size)
	{
		while (line->index + (stop_index - node->buf.pos + 1) + 2 >= line->size)
			line->size += 1024;
		new_line = malloc(line->size);
		if (!new_line)
			return (ft_free(&line->buffer, node, 1, head));
		i = 0;
		while (i < line->index)
		{
			new_line[i] = line->buffer[i];
			i++;
		}
		free(line->buffer);
		line->buffer = new_line;
	}
	while (node->buf.pos <= stop_index)
		line->buffer[line->index++] = node->buf.buffer[node->buf.pos++];
	line->buffer[line->index] = '\0';
	return (line->buffer);
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

static char	*ft_read_line(int fd, t_node *node, t_node **head)
{
	t_line	line;
	int		status;

	line.index = 0;
	line.size = 1024;
	line.buffer = malloc(line.size);
	if (!line.buffer)
		return (ft_free(&line.buffer, node, 1, head));
	while (1)
	{
		status = ft_fill_buffer(fd, &line, &node->buf);
		if (status == -1)
			return (ft_free(&line.buffer, node, 1, head));
		if (status == 0)
			return (ft_free(&line.buffer, node, 1, head));
		if (status == 2)
			return (ft_free(&line.buffer, node, 0, head));
		line.buffer = ft_append_toline(&line, node, head);
		if (!line.buffer)
			return (ft_free(&line.buffer, node, 0, head));
		if (node->buf.pos > 0 && node->buf.buffer[node->buf.pos - 1] == '\n')
			return (line.buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_node	*head;
	t_node			*node;

	node = ft_get_node(&head, fd);
	if (!node)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || node->buf.n_read == -1)
		return (NULL);
	if (!node->buf.buffer)
		node->buf.buffer = malloc((size_t)BUFFER_SIZE);
	if (!node->buf.buffer)
		return (ft_free(NULL, node, 0, head);
	return (ft_read_line(fd, node, &head));
}
