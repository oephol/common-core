#include "./../../push_swap.h"

void	ft_count_operatins(t_op_log *log, t_bench *bench)
{
	t_op_node	*node;

	node = log->head;
	while (node)
	{
		bench->total_ops++;
		bench->op_count[node->operation]++;
		node = node->next;
	}
}
void	ft_print_int(int x)
{
	char	c;

	if (x < 10)
	{
		c = x % 10 + '0';
		write(2, &c, 1);
	}
	else
	{
		ft_print_int(x / 10);
		c = x % 10 + '0';
		write(2, &c, 1);
	}
}
void	ft_print_disorder(double x)
{
		int	n;

	n = (int)x;
	if (n < 10)
		write (2, "0", 1);
	ft_print_int(n);
	write(2, ".", 1);
	n = (x - n) * 100;
	if (n)
		ft_print_int(n);
	else
		write(2, "00", 2);
}