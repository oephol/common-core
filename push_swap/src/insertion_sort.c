#include "push_swap.h"

void	insertion_sort(t_stack *a, t_stack *b, t_op_lst	*ops)
{
	t_node	*max;
	int		i;

	i = 0;
	max = ft_get_max(a);
	printf("%d\n", max->n);
	while (i < a->size)
	{
		//j = 0;
		while (a->head->n < a->head->next->n)
			ft_do_op("ra", ops, a, b);
		if (a->head != max)
		{
			ft_do_op("pb", ops, a, b);
			while (b->head->n > a->head->n)
				ft_do_op("ra", ops, a, b);
			ft_do_op("pa", ops, a, b);
		}
		else
			ft_do_op("ra", ops, a, b);
		i++;
	}
}
