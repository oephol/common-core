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

// void    ft_handle_error(t_stack *a, t_stack *b, t_ops_lst *ops)
// {
//     ft_clear(a);
//     ft_clear(b);
//     ft_clear_
// }

// void    ft_optimise(t_op_list *ops)
// {
//     t_op_node   *temp;

//     temp = ops->head;
//     while (temp)
//     {
//         if (!ft_strcmp(temp->op, "sa") && !ft_strcmp(temp->op, "sa"))
//         {

//         }
//         temp = temp->next;
//     }
// }