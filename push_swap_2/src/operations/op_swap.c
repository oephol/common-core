#include "./../../push_swap.h"

void	ft_op_sa(t_push_swap *ps)
{
	t_operation	insert;

	insert = op_sa;
	if (ft_optimise_swap(&ps->log, &insert))
		if (!ft_append_log(&ps->log, insert))
			ft_free_all(ps, 1);
	ft_swap(&ps->a);
}

void	ft_op_sb(t_push_swap *ps)
{
	t_operation	insert;

	insert = op_sb;
	if (ft_optimise_swap(&ps->log, &insert))
		if (!ft_append_log(&ps->log, insert))
			ft_free_all(ps, 1);
	ft_swap(&ps->b);
}

void	ft_op_ss(t_push_swap *ps)
{
	t_operation	insert;

	insert = op_ss;
	if (ft_optimise_swap(&ps->log, &insert))
		if (!ft_append_log(&ps->log, insert))
			ft_free_all(ps, 1);
	ft_swap(&ps->a);
	ft_swap(&ps->b);
}