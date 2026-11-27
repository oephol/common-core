#include "./../../push_swap.h"

void	ft_push_top(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	else if (stack->size == 1)
	{
		stack->head->next = node;
		stack->head->prev = node;
		node->next = stack->head;
		node->prev = stack->head;
	}
	else if (stack->size > 1)
	{
		node->next = stack->head;
		node->prev = stack->head->prev;
		node->prev->next = node;
		node->next->prev = node;
	}
	stack->head = node;
	stack->size++;
}

int	ft_push_bottom(t_stack *stack, t_node *node)
{
	if (!node)
		return (-1);
	ft_push_top(stack, node);
	if (stack->size > 1)
		stack->head = node->next;
	return (1);
}
