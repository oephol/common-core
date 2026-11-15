/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:30:44 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/27 13:37:01 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	total_size = nmemb * size;
	mem = malloc(total_size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
