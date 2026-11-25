#include "push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int ft_set_flags(char *s, t_flags *flags)
{
	int i;

	i = 0;
	if (!ft_strcmp(s, "simple"))
		flags->simple = 1;
	else if (!ft_strcmp(s, "medium"))
		flags->medium = 1;
	else if (!ft_strcmp(s, "complex"))
		flags->complex = 1;
	else if (!ft_strcmp(s, "adaptive"))
		flags->adaptive = 1;
	else if (!ft_strcmp(s, "bench"))
		flags->bench = 1;
	else
		return (-1);
	return (1);
}

int ft_isnumeric(char *s)
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

int	ft_duplicate(t_stack *a, int n)
{
	t_node	*temp;

	temp = a->head;
	while (temp)
	{
		if (n == temp->n)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int ft_read_input(t_stack *a, t_flags *flags, char **av, int ac)
{
	int i;
	int	n;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			ft_set_flags(av + i + 2, flags);
			i++;
		}
		else
		{
			while (i < ac)
			{
				n = ft_atoi(av[i]);
				if (!ft_isnumeric(av[i]) || ft_duplicate(a, n))
					return (-1);
				push_bottom(&a, ft_new_node(n));
				i++;
			}
		}
		if (av)
		i++;
	}
}

float ft_disorder(t_stack *a)
{
	int disorder;
	int pairs;
	t_node *temp1;
	t_node *temp2;

	temp1 = a->head;
	disorder = 0;
	while (temp1)
	{
		temp2 = a->head;
		while (temp2)
		{
			pairs++;
			if (temp1->n > temp2->n)
				disorder++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return ((float)disorder / pairs);
}