#include "./../../push_swap.h"

void	ft_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->next;
}

void	ft_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->prev;
}
