#include "./../../push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *node;
	int		i;

    if (!stack || stack->size < 2)
        return (1);
	i = 0;
    node = stack->head;
    while (i++ < stack->size)
    {
        if (node->value > node->next->value)
            return (0);
        node = node->next;
    }
    return (1);
}

t_node	*ft_get_max(t_stack *stack)
{
	t_node	*node;
	int		i;
	t_node	*max;

	if (!stack || !stack->head)
		return (NULL);
	node = stack->head;
	max = stack->head;
	i = 0;
	while (i++ < stack->size)
	{
		if (max->value < node->value)
			max = node;
		node = node->next;
	}
	return (max);
}

t_node	*ft_get_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;
	int		i;

	if (!stack || !stack->head)
		return (NULL);
	node = stack->head;
	min = stack->head;
	i = 0;
	while (i++ < stack->size)
	{
		if (min->value > node->value)
			min = node;
		node = node->next;
	}
	return (min);
}
