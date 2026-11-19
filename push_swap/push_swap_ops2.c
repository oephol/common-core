#include "push_swap.h"

void swap_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate(t_stack *s)
{
	t_node	*node;
	
	node = pop(s);
	ft_add_back(s, node);
}

void	rotate_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	pop_push(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (a->size == 0)
		return ;
	node = pop(a);
	push(b, node);
}

void	reverse_rotate(t_stack *s)
{
	t_node	*top;
	t_node	*bottom;

	top = pop_top(s);
	bottom = pop_bottom(s);
	push_bottom(s, top);
	push_top(s, bottom);
}

void	reverse_rotate_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}