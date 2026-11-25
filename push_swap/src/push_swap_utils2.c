#include "push_swap.h"

int is_sorted(t_stack *a)
{
    t_node *current;

    if (!a || a->size < 2)
        return (1);
    current = a->head;
    while (current->next)
    {
        if (current->n > current->next->n)
            return (0);
        current = current->next;
    }
    return (1);
}

void    ft_handle_error(t_stack *a, t_stack)