#include "push_swap.h"

t_node	*ft_median_three(t_stack *s)
{
	t_node	*middle;
	t_node	*median;
	int		i;

	i = 0;
	middle = s->head;
	while (i < s->size / 2)
	{
		middle = middle->next;
		i++;
	}
	if (s->head->n < middle->n && s->head->n < s->tail->n)
	{
		if (middle->n < s->tail->n)
			median = middle;
		else
			median = s->tail;
	}
	else if (s->head->n > middle->n && s->head->n > s->tail->n)
	{
		if (middle->n > s->tail->n)
			median = middle;
		else
			median = s->tail;
	}
	else
		median = s->head;
	return (median);
}

// void	get_pivot_to_top(t_stack *a, t_stack *b, t_op_lst *ops)
// {
// 	t_node	*pivot;

// 	pivot = ft_median_three(a);
// 	if (pivot != s->tail)
// 	{
// 		while (s->head != pivot)
// 			ft_do_op()
// 	}
// }

void	quick_sort(t_stack *a, t_stack *b, t_op_lst *ops, int size)
{
	t_node	*pivot;

	pivot = ft_median_three(a);
	if (pivot != a->tail)
	{
		while (pivot != a->head)
			ft_do_op("ra", ops, a, b);
	}
	else
		ft_do_op("rra", ops, a, b);
	ft_do_op("pd", ops, a, b);
	
}
