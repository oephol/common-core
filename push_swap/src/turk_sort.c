#include "push_swap.h"


int	ft_get_position(t_node *head, t_node *node)
{
	int	pos;

	pos = 0;
	while (head && head != node)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}

void	ft_sort_three(t_stack *a, t_stack *b, t_op_list *ops)
{
	if (a->head->n > a->head->next->n)
		ft_do_op("sa", ops, a, b);
	ft_do_op("ra", ops, a, b);
	if (a->head->n > a->head->next->n)
		ft_do_op("sa", ops, a, b);
	ft_do_op("rra", ops, a, b);
	if (a->head->n > a->head->next->n)
		ft_do_op("sa", ops, a, b);
}

void	turk_sort(t_stack *a, t_stack *b, t_op_list *ops)
{
	int	i;

	i = 0;
	while (i < a->size - 3)
	{
		ft_do_op("pb", ops, a, b);
		i++;
	}
	ft_sort_three(a, b, ops);
	i = 0;
	while (i < b->size)
	{

	}
}
