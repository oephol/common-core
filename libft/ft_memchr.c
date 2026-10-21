/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:39:03 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/19 14:58:15 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return (src + i);
		i++;
	}
	return (NULL);
}
