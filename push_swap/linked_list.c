#include "push_swap.h"

t_node	*ft_new_node(int n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->n = n;
	return (new);
}

void	ft_clear(t_stack *s)
{
	t_node	*temp;

	while (s->head)
	{
		temp = s->head;
		s->head = s->head->next;
		free(temp);
	}
	s->tail = NULL;
	s->size = 0;
}
