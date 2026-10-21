/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:03:28 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/21 11:28:53 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
			while (i + j < len && little[j] && big[i + j] == little[j])
				j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
