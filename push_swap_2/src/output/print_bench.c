#include "./../../push_swap.h"

static void	ft_print_flag(t_flags *flags)
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

static void	ft_print_strategy(int s)
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

static void	ft_print_op_count(int *arr)
{
	write(2, "[bench] sa: ", 12);
	ft_print_int(arr[0]);
	write(2, " sb: ", 5);
	ft_print_int(arr[1]);
	write(2, " ss: ", 5);
	ft_print_int(arr[2]);
	write(2, " pa: ", 5);
	ft_print_int(arr[3]);
	write(2, " pb: ", 5);
	ft_print_int(arr[4]);
	write(2, "\n", 1);
	write(2, "[bench] ra: ", 12);
	ft_print_int(arr[5]);
	write(2, " rb: ", 5);
	ft_print_int(arr[6]);
	write(2, " rr: ", 5);
	ft_print_int(arr[7]);
	write(2, " rra: ", 5);
	ft_print_int(arr[8]);
	write(2, " rrb: ", 5);
	ft_print_int(arr[9]);
	write(2, " rrr: ", 5);
	ft_print_int(arr[10]);
	write(2, "\n", 1);
}

void	ft_print_bench(t_push_swap *ps, t_flags *flags)
{
	ft_count_operatins(&ps->log, &flags->bench_info);
	write(2, "[bench] disorder: ", 18);
	ft_print_disorder(flags->bench_info.disorder * 100);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	ft_print_flag(flags);
	ft_print_strategy(flags->bench_info.strategy);
	write(2, "[bench] total_ops: ", 19);
	ft_print_int(flags->bench_info.total_ops);
	write(2, "\n", 1);
	ft_print_op_count(flags->bench_info.op_count);
}
