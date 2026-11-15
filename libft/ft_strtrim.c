/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:22:27 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/29 12:26:09 by oezzahi          ###   ########.fr       */
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
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, (char *)s + start, size);
	return (copy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	if (!*set)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	start = 0;
	while (ft_isinset(s1[start], set) && start < end)
		start++;
	if (start == end && ft_isinset(s1[end], set))
		return (ft_strdup(""));
	while (ft_isinset(s1[end], set) && end > 0)
		end--;
	return (ft_copy(s1, start, end));
}
