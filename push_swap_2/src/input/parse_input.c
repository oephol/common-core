/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oezzahi <oezzahi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 10:50:27 by oezzahi           #+#    #+#             */
/*   Updated: 2026/11/27 10:58:19 by oezzahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../push_swap.h"

static int	ft_is_multi_flags(t_flags *flags)
{
	if (flags->simple == 0 && flags->medium == 0 && flags->complex == 0\
	&& flags->adaptive == 0)
		return (0);
	return (1);
}
static int	ft_set_flags(char *s, t_flags *flags)
{
	if (!ft_strcmp(s, "bench"))
		flags->bench = 1;
	else if (!ft_is_multi_flags(flags))
	{
		if (!ft_strcmp(s, "simple"))
			flags->simple = 1;
		else if (!ft_strcmp(s, "medium"))
			flags->medium = 1;
		else if (!ft_strcmp(s, "complex"))
			flags->complex = 1;
		else if (!ft_strcmp(s, "adaptive"))
			flags->adaptive = 1;
	}
	else
		return (-1);
	return (1);
}

static int ft_is_number(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_exist_dup(t_stack *a, int n)
{
	int		i;
	t_node	*temp;

	i = 0;
	if (!a->head)
		return (0);
	temp = a->head;
	while (i < a->size)
	{
		if (n == temp->value)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

int	ft_parse_input(t_flags *flags, t_stack *a, int ac, char **av)
{
	int	n;
	int	i;

	i = 0;
	while (i < ac && (av[i][0] == '-' && av[i][1] == '-'))
	{
		if (ft_set_flags(av[i] + 2, flags) == -1)
			return (-1);
		i++;
	}
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (!ft_is_number(av[i]) || ft_exist_dup(a, n))
			return (-1);
		push_bottom(a, ft_new_node(n));
		i++;
	}
	return (1);
}
