#include "push_swap.h"

void bubble_sort(t_stack *a, t_op_lst *ops)
{
	t_node *max;
	int i;
	int j;
	// int swaped;

	max = ft_get_max(a);
	print_list(a);
	i = 0;
	// swaped = 1;
	while (i < a->size)// && swaped)
	{
		j = 0;
		// swaped = 0;
		while (j < a->size - i)
		{
			if (a->head->n > a->head->next->n && a->head != max)
			{
				// swaped = 1;
				ft_do_op("sa", ops, a, NULL);
				ft_do_op("ra", ops, a, NULL);
			}
			else
				ft_do_op("ra", ops, a, NULL);
			j++;
		}
		i++;
	}
	while (a->tail != max)
		ft_do_op("ra", ops, a, NULL);
}
