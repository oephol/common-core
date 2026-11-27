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

	if (x == 100)
		write (2, "100", 3);
	else
	{
		c = x / 10 + '0';
		write(2, &c, 1);
		c = x % 10 + '0';
		write(2, &c, 1);
	}
}
void	ft_print_float(float x)
{
	int	n;

	n = (int)x;
	ft_print_int(x);
	write(2, ".", 1);
	n = (x - n) * 100;
	ft_print_int(n);
}

void	ft_print_flag(t_flags *flags)
{
	if (flags->adaptive)
		write(2, "adaptive", 8);
	else if (flags->simple)
		write(2, "simple", 6);
	else if (flags->medium)
		write(2, "medium", 6);
	else
		write(2, "complex", 7);
}

void	ft_print_bench(t_push_swap *ps, t_flags *flags)
{
	ft_count_operatins(&ps->log, &flags->bench_info);
	write(2, "[bench] disorder: ", 18);
	ft_print_float(flags->bench_info.disorder);
	write(2, "%\n", 2);

}
