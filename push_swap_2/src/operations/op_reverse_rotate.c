#include "./../../push_swap.h"

void	ft_op_rra(t_push_swap *ps)
{
	t_operation	insert;

	insert = op_rra;
	if (ft_optimise_swap(&ps->log, &insert))
		if (!ft_append_log(&ps->log, insert))
			ft_free_all(ps, 1);
	ft_reverse_rotate(&ps->a);
}

void	ft_op_rrb(t_push_swap *ps)
{
	t_operation	insert;

	insert = op_rrb;
	if (ft_optimise_swap(&ps->log, &insert))
		if (!ft_append_log(&ps->log, insert))
			ft_free_all(ps, 1);
	ft_reverse_rotate(&ps->b);
}

void	ft_op_rrr(t_push_swap *ps)
{
	if (!ft_append_log(&ps->log, op_rrr))
		ft_free_all(ps, 1);
	ft_reverse_rotate(&ps->a);
	ft_reverse_rotate(&ps->b);
}