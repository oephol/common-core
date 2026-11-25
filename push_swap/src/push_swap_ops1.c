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
	else
		s->tail = NULL;
    temp->next = NULL;
    s->size--;
	return (temp);
}

t_node	*pop_bottom(t_stack *s)
{
	t_node	*temp;

	if (s->size == 0)
		return (NULL);
	temp = s->tail;
	s->tail = s->tail->prev;
    if (s->tail)
	    s->tail->next = NULL;
    else
        s->head = NULL;
	temp->prev = NULL;
    s->size--;
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
    if (!node)
        return ;
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
