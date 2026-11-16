/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:59:21 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/15 10:07:48 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buf
{
	char	*buffer;
	size_t	pos;
	ssize_t	n_read;
}			t_buf;

typedef struct s_line
{
	char	*buffer;
	size_t	index;
	size_t	size;
}			t_line;

char	*ft_read_line(int fd, t_buf *buf);
char	*get_next_line(int fd);

#endif