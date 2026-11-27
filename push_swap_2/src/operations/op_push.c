#include "./../../push_swap.h"

static void	ft_pop_push(t_stack *s1, t_stack *s2)
{
	t_node	*node;

	if (!s1->head)
		return ;
	node = ft_pop_top(s1);
	ft_push_top(s2, node);
}

void	ft_op_pa(t_push_swap *ps)
{
	ft_append_log(&ps->log, op_pa);
	ft_pop_push(&ps->b, &ps->a);
}

void	ft_op_pb(t_push_swap *ps)
{
	ft_append_log(&ps->log, op_pb);
	ft_pop_push(&ps->a, &ps->b);
}