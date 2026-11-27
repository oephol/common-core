#include "./../../push_swap.h"

void	ft_op_rra(t_push_swap *ps)
{
	ft_reverse_rotate(&ps->a);
}

void	ft_op_rrb(t_push_swap *ps)
{
	ft_reverse_rotate(&ps->b);
}

void	ft_op_rrr(t_push_swap *ps)
{
	ft_reverse_rotate(&ps->a);
	ft_reverse_rotate(&ps->b);
}