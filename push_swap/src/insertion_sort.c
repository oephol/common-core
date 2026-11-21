#include "push_swap.h"

void insertion_sort(t_stack *a, t_stack *b, t_op_lst *ops)
{
	t_node *max;
	int i;
	int j;
	int swaped = 1;

	i = 0;
	max = ft_get_max(a);
	// printf("%d\n", max->n);
	while (i < a->size && swaped)
	{
		swaped = 0;
		j = 0;
		while (j < a->size - i)
		{
			while (a->head->n > a->head->next->n && a->head != max)
			{
				swaped = 1;
				ft_do_op("pb", ops, a, b);
				while (b->head->n > a->head->n)
					ft_do_op("ra", ops, a, b);
				ft_do_op("pa", ops, a, b);
			}
			ft_do_op("ra", ops, a, b);
			j++;
		}
		i++;
	}
	while (a->tail != max)
		ft_do_op("ra", ops, a, NULL);
}
