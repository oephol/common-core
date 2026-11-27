#include "push_swap.h"

void    ft_push_swap(t_push_swap *ps, t_flags *flags)
{
	//if (flags->bench_info.strategy == 1)
	//	ft_simple_algo(ps);
	//else if (flags->bench_info.strategy == 2)
	//	ft_meduim_algo(ps);
	//else
	//	ft_complex_algo(ps);
	//ft_print_operations(ps, flags);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
    t_flags		flags;

	if (argc < 2)
		return (0);
    ft_bzero(&flags, sizeof(t_flags));
    ft_bzero(&ps, sizeof(t_push_swap));
	if (ft_parse_input(&flags, &ps.a, argc, argv) == -1)
		ft_error(&ps);
	flags.bench_info.disorder = ft_disorder(&ps.a, 0, 0);
	flags.bench_info.strategy = ft_set_strategy(&flags);
	ft_print_list(&ps.a);
	printf("\nsize: %d\n", ps.a.size);
	//ft_push_swap(&ps, &flags);
	return (0);
}
