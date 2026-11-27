#include "./../../push_swap.h"

static void	ft_print_op(t_operation op)
{
	char *const arr[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;
	
	i = 0;
	while (arr[(int)op][i])
	{
		write(1, &arr[(int)op][i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_opretions(t_push_swap *ps, t_flags *flags)
{
	t_op_node	*node;

	node = ps->log.head;
	while (node)
	{
		ft_print_op(node->operation);
		node = node->next;
	}
	if (flags && flags->bench)
		ft_print_bench(ps, flags);
}