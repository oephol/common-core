#include "./../../push_swap.h"

void	ft_op_ra(t_push_swap *ps)
{
	if (!ft_append_log(&ps->log, op_ra))
		ft_free_all(ps, 1);
	ft_rotate(&ps->a);
}

void	ft_op_rb(t_push_swap *ps)
{
	if (!ft_append_log(&ps->log, op_rb))
		ft_free_all(ps, 1);
	ft_rotate(&ps->b);
}

void	ft_op_rr(t_push_swap *ps)
{
	if (!ft_append_log(&ps->log, op_rr))
		ft_free_all(ps, 1);
	ft_rotate(&ps->a);
	ft_rotate(&ps->b);
}