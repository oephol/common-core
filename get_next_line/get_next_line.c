/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:59:29 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/14 22:11:45 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buf	buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf.buffer)
		buf.buffer = malloc((size_t)BUFFER_SIZE);
	if (!buf.buffer)
		return (NULL);
	return (ft_read_line(fd, &buf));
}
