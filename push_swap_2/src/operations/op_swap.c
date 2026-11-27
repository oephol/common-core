#include "./../../push_swap.h"

void	ft_op_sa(t_push_swap *ps)
{
	ft_swap(&ps->a);
}

void	ft_op_sb(t_push_swap *ps)
{
	ft_swap(&ps->b);
}

void	ft_op_ss(t_push_swap *ps)
{
	ft_swap_a(ps);
	ft_swap_b(ps);
}