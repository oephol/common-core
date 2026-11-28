#include "./../../push_swap.h"

void	ft_bzero(void *mem, int size)
{
	int				i;
	unsigned char	*p;

	p = mem;
	i = 0;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
}

double	ft_disorder(t_stack *a, t_node *temp1, t_node *temp2)
{
	int disorder;
	int pairs;
	int	i;
	int	j;

	temp1 = a->head;
	disorder = 0;
	i = 0;
	while (i++ < a->size)
	{
		temp2 = temp1->next;
		j = i;
		while (j++ < a->size)
		{
			pairs++;
			if (temp1->value > temp2->value)
				disorder++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return ((double)disorder / pairs);
}

int	ft_set_strategy(t_flags *flags)
{
	if (flags->adaptive)
	{
		if (flags->bench_info.disorder < 0.2)
			return (1);
		else if (flags->bench_info.disorder >= 0.5)
			return (3);
		else
			return (2);
	}
	else if (flags->simple)
		return (1);
	else if (flags->medium)
		return (2);
	else
		return (3);
}
