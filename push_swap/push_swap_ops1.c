#include "push_swap.h"

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
    s->size--;
	return (temp);
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