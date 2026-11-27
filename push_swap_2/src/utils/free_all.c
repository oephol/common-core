#include "./../../push_swap.h"

void	ft_free_all(t_push_swap *ps, int status)
{
	ft_clear_stack(&ps->a);
	ft_clear_stack(&ps->b);
	ft_clear_log(&ps->log);
	if (status)
		exit(1);
}

void	ft_error(t_push_swap *ps)
{
	write(2, "Error\n", 6);
	ft_free_all(ps, 1);
}