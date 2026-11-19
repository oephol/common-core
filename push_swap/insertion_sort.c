#include "push_swap.h"

static int	ft_get_max(t_stack *a)
{
	int			i;
	int			max;

	i = 0;
	max = a->head->n;
	while (i < a->size)
	{
        //printf("max: %d, head: %d\n", max, a->head->n);
		if (max < a->head->n)
			max = a->head->n;
		i++;
		rotate(a);
	}
	return (max);
}

void	insertion_sort(t_stack *a, t_stack *b, t_op_lst	*ops)
{
	int			max;
	int			loop;

	loop = 1;
	max = ft_get_max(a);
	print_list(a);
	while (loop)
	{
		loop = 0;
		while (a->head->n < a->head->next->n)
		{
			rotate(a);
			ops->tail = link_op_lst(ops, "ra");
            print_list(a);
		}
		if (a->head->n != max)
		{
			loop = 1;
			pop_push(a, b);
			ops->tail = link_op_lst(ops, "pb");
			while (b->head->n > a->head->n)
			{
				rotate (a);
				ops->tail = link_op_lst(ops, "ra");
			}
			pop_push(b, a);
			ops->tail = link_op_lst(ops, "pa");
			rotate(a);
			ops->tail = link_op_lst(ops, "ra");
		}
        rotate(a);
        ops->tail = link_op_lst(ops, "ra");
	}
}
