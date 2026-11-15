/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 08:38:18 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/08 09:38:34 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *s, t_out *out)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	out->error = write(1, s, len);
	if (out->error == -1)
		return ;
	out->count += out->error;
}

void	ft_print_char(int c, t_out *out)
{
	out->error = write(1, &c, 1);
	if (out->error != -1)
		out->count++;
}
