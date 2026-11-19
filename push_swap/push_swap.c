#include "push_swap.h"

void	push_swap(t_stack *a)
{
	t_stack		b = {NULL, NULL, 0};
	t_op_lst	ops = {NULL, NULL};

	ops = (t_op_lst){0,0};
	insertion_sort(a, &b, &ops);
	ft_print_ops(&ops);
}
int	ft_get_max(t_stack *a)
{
	int			i;
	int			max;

	i = 0;
	max = a->head->n;
	while (i < a->size)
	{
        printf("max: %d, head: %d, size: %d\n", max, a->head->n, a->size);
		if (max < a->head->n)
			max = a->head->n;
		i++;
		rotate(a);
	}
	return (max);
}

int	main()
{
	int arr[] = {1, -8, 10, 15, 2, 0, 12, -13, 5, -15};
	int i = 0;
	t_stack	a = {NULL, NULL, 0};
	t_node *temp;

	while (i < 10)
	{
		push_bottom(&a, ft_new_node(arr[i]));
		i++;
	}
    //print_list(&a);
    //printf("%d\n", a.size);
    //printf("max: %d\n", ft_get_max(&a));
	push_swap(&a);
	temp = a.head;
	while(temp)
	{
		printf("%d, ", temp->n);
		temp = temp->next;
	}
	return (0);
}