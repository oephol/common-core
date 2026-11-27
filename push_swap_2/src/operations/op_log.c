#include "./../../push_swap.h"

static t_op_node	*ft_new_op_node(t_operation op)
{
	t_op_node	*new;

	new = malloc(sizeof(t_op_node));
	if (!new)
		return (NULL);
	new->operation = op;
	new->next = NULL;
	return(new);
}

t_node	*ft_append_log(t_op_log *log, t_operation op)
{
	t_op_node	*node;

	node = ft_new_op_node(op);
	if (!node)
		return (NULL);
	if (!log->head)
	{
		log->head = node;
		log->tail = node;
	}
	else
	{
		log->tail->next = node;
		log->tail = node;
	}
	return (node);
}

void	ft_clear_log(t_op_log *log)
{
	t_op_node	*node;
	
	while (log->head)
	{
		node = log->head;
		log->head = node->next;
		free(node);
	}
	log->tail = NULL;
}

