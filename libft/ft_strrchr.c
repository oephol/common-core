/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:30:15 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/29 13:46:06 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*last_occurence;
	size_t		i;

	i = 0;
	last_occurence = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_occurence = (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		last_occurence = (char *)s + i;
	return (last_occurence);
}
