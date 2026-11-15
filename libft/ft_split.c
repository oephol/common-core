/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:58:25 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/27 14:41:19 by oezzahi          ###   ########.fr       */
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

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_cpy_word(char *dest, char const *s, char c, size_t i)
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
	while (index > 0)
	{
		index--;
		free(list[index]);
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
	if (!list)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			list[index] = malloc(ft_word_len((char *)s + i, c) + 1);
		if (s[i] && !list[index])
			return (ft_free(list, index));
		if (s[i])
			i = ft_cpy_word(list[index++], s, c, i);
	}
	list[index] = NULL;
	return (list);
}
