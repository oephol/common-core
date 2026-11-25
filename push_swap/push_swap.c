#include "push_swap.h"

void	push_swap(t_stack *a,t_op_lst *ops, t_flags *flags)
{
	t_stack	b;

	//insertion_sort(a, &b, &ops);
	bubble_sort(a, ops);
	ft_print_ops(ops);
	ft_clear(&b);
}
void print_list(t_stack *a)
{
	t_node *temp = a->head;

	while (temp)
	{
		printf("%d, ", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_op_lst	ops;
	t_flags		flags;

	ops = (t_op_lst){0};
	flags = (t_flags){0};
	ft_read_input(&a, &flags, argv, argc);
    //print_list(&a);
    printf("%d\n", a.size);
    //printf("max: %d\n", ft_get_max(&a));
	//push_swap(&a);
	ft_clear(&a);
	return (0);
}