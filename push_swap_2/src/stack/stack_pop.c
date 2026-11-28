#include "./../../push_swap.h"

static void	ft_pop(t_stack *stack, t_node *node)
{
	if (stack->size == 2)
	{
		stack->head->prev = NULL;
		stack->head->next = NULL;
	}
	else if (stack->size > 2)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
}

t_node	*ft_pop_top(t_stack *stack)
{
	t_node	*node;

	if (!stack->head)
		return (NULL);
	node = stack->head;
	stack->head = node->next;
	ft_pop(stack, node);
	return (node);
}

t_node	*ft_pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (!stack->head)
		return (NULL);
	if (stack->size == 1)
		return (ft_pop_top(stack));
	node = stack->head->prev;
	ft_pop(stack, node);
	return (node);
}
