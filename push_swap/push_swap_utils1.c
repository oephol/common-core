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

t_op	*link_op_lst(t_op_lst *lst, char *s)
{
	t_op	*new;

	if (!lst)
		return (NULL);
	new = malloc(sizeof(lst));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->op = ft_strdup(s);
	if (!new->op)
	{
		free (new);
		return (NULL);
	}
	if (!lst->head)
		lst->head = new;
	else
		lst->tail->next = new;
	return (new);
}

void	ft_print_ops(t_op_lst *ops)
{
	int	i;
	t_op	*temp;

	temp = ops->head;
	while (temp)
	{
		i = 0;
		while (temp->op[i])
		{
			write(1, &temp->op[i], 1);
			i++;
		}
		write(1, "\n", 1);
		temp = temp->next;
	}
}
