#include "push_swap.h"

void	ft_replace(t_op_list *ops, t_op_node *a, t_op_node *b, char *op)
{
	t_op_node	*temp1;
	t_op_node	*new;

	new = malloc(sizeof(t_op_list));
	if (!new)
		return ;
	new->next = NULL;
	new->operation = ft_strdup(op);
	temp1 = ops->head;
	if (temp1 != a)
		ops->head = new;
	else
	{
		while (temp1->next != a)
			temp1 = temp1->next;
		temp1->next = new;
	}
	new->next = b->next;
	free(a->operation);
	free(a);
	free(b->operation);
	free(b);
}

void	ft_cancel(t_op_list *ops)
{
	t_op_node	*temp;

	temp = ops->head;
	while (temp)
	{
		if (!ft_strcmp(temp->operation, "sa") && !ft_strcmp(temp->next->operation, "sa"))
		{

		}
	}
}
