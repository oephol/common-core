#include "./../../push_swap.h"

void	ft_op_ra(t_push_swap *ps)
{
	ft_rotate(&ps->a);
}

void	ft_op_rb(t_push_swap *ps)
{
	ft_rotate(&ps->b);
}

void	ft_op_rr(t_push_swap *ps)
{
	ft_rotate(&ps->a);
	ft_rotate(&ps->b);
}