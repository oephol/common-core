/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:59:24 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/15 10:00:17 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_node	*ft_new_node(int fd)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->fd = fd;
	new->buf.buffer = NULL;
	new->buf.pos = 0;
	new->buf.n_read = 0;
	return (new);
}

t_node	*ft_insert_before(t_node **head, t_node *node, int fd)
{
	t_node	*new;

	new = ft_new_node(fd);
	if (!new)
		return (NULL);
	if (node->prev)
		node->prev->next = new;
	else
		*head = new;
	new->prev = node->prev;
	node->prev = new;
	new->next = node;
	return (new);
}

t_node	*ft_get_node(t_node	**head, int fd)
{
	t_node	*temp;

	if (!*head)
	{
		*head = ft_new_node(fd);
		return (*head);
	}
	temp = *head;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		if (!temp->next || temp->fd > fd)
			break ;
		temp = temp->next;
	}
	if (!temp->next)
	{
		temp->next = ft_new_node(fd);
		temp->next->prev = temp;
	}
	else
		return (ft_insert_before(head, temp, fd));
	return (temp->next);
}

char	*ft_free(char **line, t_node *node, int yes_line, t_node **head)
{
	if (yes_line)
	{
		free(*line);
		*line = NULL;
	}
	if (!node->prev)
		*head = node->next;
	else
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node->buf.buffer);
	free(node);
	return (*line);
}

size_t	ft_nl_index(char *s, size_t i, size_t len)
{
	if (!s || !len)
		return (0);
	while (i < len - 1 && s[i] != '\n')
		i++;
	return (i);
}
