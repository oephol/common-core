#include "./../../push_swap.h"

void	ft_sort_top_three(t_push_swap *ps)
{
	if (ft_is_sorted(&ps->a))
		return ;
	if (ps->a.size == 2)
	{
		if (ps->a.head->value > ps->a.head->next->value)
			ft_op_ra(ps);
		return;
	}
	if (ps->a.head->value > ps->a.head->next->value)
		ft_op_sa(ps);
	ft_op_ra(ps);
	if (ps->a.head->value > ps->a.head->next->value)
		ft_op_sa(ps);
	ft_op_rra(ps);
	if (ps->a.head->value > ps->a.head->next->value)
		ft_op_sa(ps);
}

void	ft_min_to_top(t_push_swap *ps)
{
	t_node	*min;
	int		pos;

	min	= ft_get_min(&ps->b);
	pos = ft_get_position(&ps->b, min);
	if (pos > ps->b.size / 2)
	{
		while (ps->b.head != min)
			ft_op_rrb(ps);
	}
	else
	{
		while(ps->b.head != min)
			ft_op_rb(ps);
	}
}

void	ft_sort_turk(t_push_swap *ps)
{
	t_node	*max;
	t_node	*min;

	if (ps->a.size < 2)
		return ;
	max = ft_get_max(&ps->a);
	min = ft_get_min(&ps->a);
	while (ps->a.size > 3)
	{
		if (ps->a.head == max || ps->a.head == min)
			ft_op_ra(ps);
		ft_op_pb(ps);
	}
	ft_sort_top_three(ps);
	while (ps->b.size != 0)
	{
		ft_min_to_top(ps);
		while (ps->a.head->value < ps->b.head->value)
			ft_op_ra(ps);
		ft_op_pa(ps);
	}
	while (ps->a.head->prev != max)
		ft_op_ra(ps);
}
