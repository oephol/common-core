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
void	ft_print_disorder(float x)
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

void	ft_print_flag(t_flags *flags)
{
	if (flags->adaptive)
		write(2, "adaptive / ", 11);
	else if (flags->simple)
		write(2, "simple / ", 9);
	else if (flags->medium)
		write(2, "medium / ", 9);
	else
		write(2, "complex / ", 10);
}

void	ft_print_strategy(int s)
{
	if (s == 1)
		write(2, "O(n^2)\n", 7);
	else if (s == 2)
	{
		write(2, "O(n", 3);
		write(2, "\u221A", 4);
		write(2, "n)\n", 3);
	}
	else if (s == 3)
		write(2, "O(n log n)\n", 11);
}

void	ft_print_bench(t_push_swap *ps, t_flags *flags)
{
	ft_count_operatins(&ps->log, &flags->bench_info);
	write(2, "[bench] disorder: ", 18);
	ft_print_disorder(flags->bench_info.disorder);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	ft_print_flag(flags);
	ft_print_strategy(flags->bench_info.strategy);
	write(2, "[bench] total_ops: ", 19);
	ft_print_int(flags->bench_info.total_ops);
	write(2, "\n", 1);
	

}
