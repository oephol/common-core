/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 21:48:08 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/13 13:47:40 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;
	size_t	dst_size;

	i = 0;
	dst_size = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	if (size == 0)
		return (src_size);
	while (dst[dst_size] && dst_size < size)
		dst_size++;
	if (dst_size >= size)
		return (size + src_size);
	while (i + dst_size < size - 1 && src[i])
	{
		dst[i + dst_size] = src[i];
		i++;
	}
	dst[i + dst_size] = '\0';
	return (dst_size + src_size);
}
