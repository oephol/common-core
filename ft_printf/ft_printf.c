/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 09:45:55 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/07 09:46:43 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fmt_spec_handler(const char *format, t_out *out, va_list *args)
{
	if (*format == 'c')
		ft_print_char(va_arg(*args, int), out);
	else if (*format == 's')
		ft_print_str(va_arg(*args, char *), out);
	else if (*format == 'p')
		ft_print_ptr(va_arg(*args, void *), out);
	else if (*format == 'i' || *format == 'd')
		ft_print_int(va_arg(*args, int), out);
	else if (*format == 'u')
		ft_print_uint(va_arg(*args, unsigned int), out);
	else if (*format == 'x')
		ft_print_hex(va_arg(*args, unsigned int), 0, out);
	else if (*format == 'X')
		ft_print_hex(va_arg(*args, unsigned int), 1, out);
	else if (*format == '%')
		ft_print_char(*format, out);
	else
		out->error = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_out	out;

	if (!format)
		return (-1);
	out.count = 0;
	out.error = 0;
	va_start(args, format);
	while (*format && out.error != -1)
	{
		if (*format == '%')
			ft_fmt_spec_handler(++format, &out, &args);
		else
		{
			out.error = write(1, format, 1);
			if (out.error != -1)
				out.count++;
		}
		format++;
	}
	va_end(args);
	if (out.error != -1)
		return (out.count);
	return (-1);
}
