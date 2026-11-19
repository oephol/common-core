#include "push_swap.h"

void	push_swap(t_stack *a)
{
	t_stack		b;
	t_op_lst	ops;

	ops = (t_op_lst){0,0};
	insertion_sort(a, &b, &ops);
	ft_print_ops(&ops);
}

int	main()
{
	int arr[] = {1, -8, 10, 15, 2, 0, 12, -13, 5, -15};
	int i = 0;
	t_stack	a;
	t_node *temp;

	a.head = a.tail = NULL;
	a.size = 0;
	while (i < 10)
	{
		push_top(&a, ft_new_node(arr[i]));
		i++;
	}
	push_swap(&a);
	temp = a.head;
	while(temp)
	{
		printf("%d, ", temp->n);
		temp = temp->next;
	}
	return (0);
}