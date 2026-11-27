#include "./../../push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 2)
	{
		ft_rotate(stack);
		return ;
	}
	node = stack->head;
	ft_rotate(stack);
	node->next = stack->head->next;
	stack->head->prev = node->prev;
	node->prev->next = stack->head;
	stack->head->next->prev = node;
	node->prev = stack->head;
	stack->head->next = node;
}