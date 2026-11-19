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

void	push_bottom(t_stack *s, t_node *node)
{
	if (!s->head)
	{
		s->head = node;
		s->tail = s->head;
		s->size++;
		return ;
	}
	s->tail->next = node;
	s->tail->next->prev = s->tail;
	s->tail = s->tail->next;
	s->size++;
	return ;
}