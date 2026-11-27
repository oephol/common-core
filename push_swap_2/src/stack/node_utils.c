#include "./../../push_swap.h"

t_node	*ft_new_node(int n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->value = n;
	return (new);
}

void	ft_clear_stack(t_stack *stack)
{
	t_node	*temp;
	int		i;

	i = 0;
	while (i < stack->size)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
		i++;
	}
	stack->head = NULL;
	stack->size = 0;
}
