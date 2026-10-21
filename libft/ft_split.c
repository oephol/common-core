/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:58:25 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/21 14:45:32 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			num++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (num);
}

static size_t	ft_strlen_local(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_strcpy(char *dest, char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (i);
}

static char	**ft_free(char **list, size_t index)
{
	while (index >= 0)
	{
		free(list[index]);
		index--;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		index;
	char		**list;

	if (!s)
		return (NULL);
	list = malloc((ft_count_strs(s, c) + 1) * sizeof(char *));
	i = 0;
	index = 0;
	while (list && s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			list[index] = malloc(ft_strlen_local((char *)s + i, c) + 1);
		if (s[i] && !list[index])
			return (ft_free(list, index));
		if (s[i])
		{
			i = ft_strcpy(list[index], s, c, i);
			index++;
		}
	}
	list[index] = NULL;
	return (list);
}
