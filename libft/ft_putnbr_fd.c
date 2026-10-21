/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:34:59 by oezzahi           #+#    #+#             */
/*   Updated: 2026/10/21 14:49:27 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (fd < 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (-1) * nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}
