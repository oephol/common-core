#include "./../../push_swap.h"

// void	ft_sort_three(t_push_swap *ps)
// {
// 	t_node	*node;
// 	int		i = 0;

// 	i = 0;
// 	node = ps->a.head;
// 	if (ps->a.size != 3)
// 		return ;
// 	while (i < 3)
// 	{
// 		if ()
// 	}
// }

void	ft_sort_top_three(t_push_swap *ps)
{
	if (ps->a.head->value > ps->a.head->next->value)
		ft_op_sa(ps);
	ft_op_ra(ps);
	if (ps->a.head->value > ps->a.head->next->value)
		ft_op_sa(ps);
	ft_op_rra(ps);
	if (ps->a.head->value > ps->a.head->next->value)
		ft_op_sa(ps);
}

void	ft_sort_turk(t_push_swap *ps)
{
	
}