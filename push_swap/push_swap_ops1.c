#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*temp;

	if (s->size < 2)
		return ;
	s->head = s->head->next;
	temp = s->head->next;
	s->head->next = s->head->prev;
	s->head->prev = NULL;
	s->head->next->next = temp;
	s->head->next->prev = s->head->next;
	if (s->size == 2)
		s->tail = s->head->next;
}
t_node	*pop_bottom(t_stack *s)
{
	t_node	*temp;

	if (s->size == 0)
		return (NULL);
	temp = s->head;
	s->head = s->head->next;
	s->head->prev = NULL;
	temp->next = NULL;
	if (s->size == 1)
		s->head = NULL;
	return (temp);
}

t_node	*pop_top(t_stack *s)
{
	t_node	*temp;

	if (s->size == 0)
		return (NULL);
	temp = s->head;
	s->head = s->head->next;
	if (s->head)
		s->head->prev = NULL;
	temp->next = NULL;
	if (s->size == 1)
		s->tail = NULL;
	return (temp);
}

void	push_top(t_stack *s, t_node *node)
{
	if (!node)
		return ;
	node->next = s->head;
	if (s->head)
		s->head->prev = node;
	s->head = node;
	if (s->size == 0)
		s->tail = node;
	s->size++;
}


void print_list(t_stack *a)
{
	t_node *temp = a->head;

	while (temp)
	{
		printf("%d, ", temp->n);
		temp = temp->next;
	}
	printf("\n");
}