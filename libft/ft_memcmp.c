/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:47:06 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/20 14:17:05 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (i < n - 1 && src1[i] == src2[i])
		i++;
	return (src1[i] - src2[i]);
}
