/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 08:52:06 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/08 09:46:13 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_in_base(unsigned long n, char *base_set, int base, t_out *out)
{
	if (n < (unsigned long)base)
	{
		out->error = write(1, &base_set[n % base], 1);
		if (out->error != -1)
			out->count++;
		return ;
	}
	ft_print_in_base(n / base, base_set, base, out);
	if (out->error != -1)
		out->error = write(1, &base_set[n % base], 1);
	if (out->error != -1)
		out->count++;
}

void	ft_print_hex(unsigned long n, int isupper, t_out *out)
{
	if (isupper)
		ft_print_in_base(n, "0123456789ABCDEF", 16, out);
	else
		ft_print_in_base(n, "0123456789abcdef", 16, out);
}

void	ft_print_ptr(void *p, t_out *out)
{
	unsigned long	n;

	if (!p)
	{
		out->error = write(1, "(nil)", 5);
		if (out->error != -1)
			out->count += out->error;
		return ;
	}
	n = (unsigned long)p;
	out->error = write(1, "0x", 2);
	if (out->error != -1)
	{
		out->count += out->error;
		ft_print_hex(n, 0, out);
	}
}

void	ft_print_int(long n, t_out *out)
{
	if (n < 0)
	{
		out->error = write(1, "-", 1);
		if (out->error != -1)
			out->count++;
		n = (-1) * n;
	}
	if (out->error != -1)
		ft_print_in_base(n, "0123456789", 10, out);
}

void	ft_print_uint(unsigned int n, t_out *out)
{
	ft_print_in_base(n, "0123456789", 10, out);
}
