/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 13:19:12 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/26 14:15:10 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
