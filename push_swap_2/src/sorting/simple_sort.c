#include "./../../push_swap.h"

void	ft_sort_top_three(t_push_swap *ps)
{
	if (is_sorted(&ps->a))
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
//int	ft_get_pos(t_stack *stack)
void	ft_sort_turk(t_push_swap *ps)
{
	int		i;
	t_node	*max;
	t_node	*min;

	if (ps->a.size < 2)
		return ;
	i = 0;
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
		i = 0;
		while (i++ < ps->a.size && (ps->b.head->value > ps->a.head->value \
			|| ps->b.head->value < ps->a.head->prev->value))
			ft_op_ra(ps);
		ft_op_pa(ps);
	}
	while (ps->a.head->prev != max)
		ft_op_ra(ps);
}
