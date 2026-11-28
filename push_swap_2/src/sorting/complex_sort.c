#include "./../../push_swap.h"

void	quick_sort_a(t_push_swap *ps, int size)
{
	int	push;
	int	i;
	int	pivot;

	i = 0;
	push = 0;
	pivot = ps->a.head->prev->value; //change to median
	while (i < size)
	{
		if (ps->a.head->value < pivot)
		{
			ft_op_pb(ps);
			push++;
		}
		else
			ft_op_ra(ps);
		i++;
	}
	quick_sort_a()
}