/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:59:21 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/15 10:11:19 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

typedef struct s_node
{
	int				fd;
	t_buf			buf;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

char	*ft_free(char **line, t_node *node, int yes_line, t_node **head);
size_t	ft_nl_index(char *s, size_t i, size_t len);
t_node	*ft_new_node(int fd);
t_node	*ft_insert_before(t_node **head, t_node *node, int fd);
t_node	*ft_get_node(t_node	**head, int fd);
char	*get_next_line(int fd);

#endif