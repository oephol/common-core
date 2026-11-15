/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:35:42 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/29 15:14:07 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joint;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joint = malloc(s1_len + s2_len + 1);
	if (!joint)
		return (NULL);
	ft_strlcpy(joint, s1, s1_len + 1);
	ft_strlcpy(joint + s1_len, s2, s2_len + 1);
	return (joint);
}
