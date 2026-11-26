#include "push_swap.h"

t_op_node	*link_op_lst(t_op_list *lst, char *s)
{
	t_op_node	*new;

	if (!lst)
		return (NULL);
	new = malloc(sizeof(t_op_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->operation = ft_strdup(s);
	if (!new->operation)
	{
		free (new);
		return (NULL);
	}
	if (!lst->head)
		lst->head = new;
	else
		lst->tail->next = new;
	return (new);
}

void	ft_clear_ops(t_op_list *ops)
{
	t_op_node	*temp;

	while (ops->head)
	{
		temp = ops->head;
		ops->head = ops->head->next;
		free(temp->operation);
		free(temp);
	}
}

void	ft_print_ops(t_op_list *ops)
{
	int			i;
	t_op_node	*temp;

	temp = ops->head;
	while (temp)
	{
		i = 0;
		while (temp->operation[i])
		{
			write(1, &temp->operation[i], 1);
			i++;
		}
		write(1, "\n", 1);
		temp = temp->next;
	}
	ft_clear_ops(ops);
}

static int	ft_record_op_second(char *op)
{
	if (op[1] == 'a')
			return (6);
	else if (op[1] == 'b')
			return (7);
	else if (op[1] == 'r')
	{
		if (op[2] == '\0')
			return (8);
		else if (op[1] == 'a')
			return (9);
		else if (op[1] == 'b')
			return (10);
		return (11);
	}
	return (0);
}

static int	ft_record_op(char *op, t_op_list *ops)
{
	ops->tail = link_op_lst(ops, op);
	if (op[0] == 's')
	{
		if (op[1] == 'a')
			return (1);
		else if (op[1] == 'b')
			return (2);
		return (3);
	}
	else if (op[0] == 'p')
	{
		if (op[1] == 'a')
			return (4);
		else if (op[1] == 'b')
			return (5);
	}
	else if (op[0] == 'r')
		return (ft_record_op_second(op));
	return (0);
}

void	ft_do_op(char *op, t_op_list *ops, t_stack *a, t_stack *b)
{
	int	flag;

	flag = ft_record_op(op, ops);
	if (flag == 1)
		swap(a);
	else if (flag == 2)
		swap(b);
	else if (flag == 3)
		swap_swap(a, b);
	else if (flag == 4)
		pop_push(b, a);
	else if (flag == 5)
		pop_push(a, b);
	else if (flag == 6)
		rotate(a);
	else if (flag == 7)
		rotate(b);
	else if (flag == 8)
		rotate_rotate(a, b);
	else if (flag == 9)
		reverse_rotate(a);
	else if (flag == 10)
		reverse_rotate(b);
	else if (flag == 11)
		reverse_rotate_rotate(a, b);
}

char	**ft_ops_name_table(void)
{
	static char	*arr[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

	return (arr);
}
