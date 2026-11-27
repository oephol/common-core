#include "push_swap.h"
# include <stdio.h>

void	ft_print_list(t_stack *s)
{
	int	i;
	t_node *node;

	i = 0;
	node = s->head;
	printf("[");
	while (i < s->size && node)
	{
		printf("%d, ", node->value);
		node = node->next;
		i++;
	}
	printf("]\n");
}