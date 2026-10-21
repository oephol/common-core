/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:22:27 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/21 14:41:14 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_copy(char const *s, size_t start, size_t end)
{
	size_t	size;
	char	*copy;

	size = end - start + 2;
	copy = malloc(size);
	ft_strlcpy(copy, (char *)s + start, size);
	return (copy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isinset(s1[start], set) && start < end)
		start++;
	if (start == end && ft_isinset(s1[end], set))
		return (ft_calloc(1, 1));
	while (ft_isinset(s1[end], set) && end > 0)
		end--;
	return (ft_copy(s1, start, end));
}
