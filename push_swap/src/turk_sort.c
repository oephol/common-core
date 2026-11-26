#include "push_swap.h"

void	turk_sort(t_stack *a, t_stack *b, t_op_list *ops)
{
	int	i;

	i = 0;
	while (i < a->size - 3)
	{
		ft_do_op("pb", ops, a, b);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (a->head->n > a->head->next->n)
		{
			ft_do_op("sa", ops, a, b);
			ft_do_op("ra", ops, a, b);
		}
		else
			ft_do_op("ra", ops, a, b);
		i++;
	}
	if (a->head->n > a->head->next->n)
		ft_do_op("ra", ops, a, b);
	i = 0;
	while (i < b->size)
	{

	}
}
