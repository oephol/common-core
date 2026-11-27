#include "./../../push_swap.h"

void	ft_op_sa(t_push_swap *ps)
{
	if (!ft_append_log(&ps->log, op_sa))
		ft_free_all(ps, 1);
	ft_swap(&ps->a);
}

void	ft_op_sb(t_push_swap *ps)
{
	if (!ft_append_log(&ps->log, op_sb))
		ft_free_all(ps, 1);
	ft_swap(&ps->b);
}

void	ft_op_ss(t_push_swap *ps)
{
	if (!ft_append_log(&ps->log, op_ss))
		ft_free_all(ps, 1);
	ft_swap_a(ps);
	ft_swap_b(ps);
}