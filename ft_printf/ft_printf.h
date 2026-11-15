/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 08:18:08 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/07 10:03:43 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_out
{
	int	count;
	int	error;
}		t_out;

int		ft_printf(const char *format, ...);
void	ft_print_str(char *s, t_out *out);
void	ft_print_char(int c, t_out *out);
void	ft_print_in_base(unsigned long n, char *base_set, int base, t_out *out);
void	ft_print_hex(unsigned long n, int isupper, t_out *out);
void	ft_print_ptr(void *p, t_out *out);
void	ft_print_int(long n, t_out *out);
void	ft_print_uint(unsigned int n, t_out *out);

#endif
