#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	n;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	n = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * n);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

t_node	*ft_get_max(t_stack *s)
{
	t_node	*temp;
	t_node	*max;

	if (!s || !s->head)
		return (NULL);
	temp = s->head;
	max = s->head;
	while (temp)
	{
		if (max->n < temp->n)
			max = temp;
		temp = temp->next;
	}
	return (max);
}
