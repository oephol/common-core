/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:30:15 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/21 14:45:38 by oezzahi          ###   ########.fr       */
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
		if ((unsigned char)c == (unsigned char)s[i])
			last_occurence = (char *)s + i;
		i++;
	}
	if (c == '\0')
		last_occurence = (char *)s + i;
	return (last_occurence);
}
