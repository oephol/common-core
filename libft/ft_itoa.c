/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 18:44:54 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/21 14:53:47 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_str(char *s, long n, unsigned int len)
{
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = (-1) * n;
	}
	while (n >= 10)
	{
		s[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	s[len - 1] = n % 10 + '0';
}

static unsigned int	ft_get_size(long n)
{
	unsigned int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = (-1) * n;
	}
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	long			nbr;
	char			*s;

	nbr = n;
	len = ft_get_size(nbr);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	ft_fill_str(s, nbr, len);
	return (s);
}
