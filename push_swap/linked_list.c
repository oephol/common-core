#include "push_swap.h"

t_node	*ft_new_node(int n)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->num = n;
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

void	*ft_add_back(t_stack *s, int n)
{
	t_node	*new;

	new = ft_new_node(n);
	if (!new)
		return (NULL);
	if (!s->head)
	{
		s->head = new;
		s->tail = s->head;
		s->size++;
		return (new);
	}
	s->tail->next = new;
	s->tail->next->prev = s->tail;
	s->tail = s->tail->next;
	s->size++;
	return (new);
}