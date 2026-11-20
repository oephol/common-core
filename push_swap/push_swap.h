#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//structs/////////////////////
typedef struct s_stack
{
	int	*arr;
	int	tail;
	int	size;
}	t_stack;

typedef struct s_op
{
	char		*op;
	struct s_op	*next;
}	t_op;

typedef	struct s_op_lst
{
	t_op	*head;
	t_op	*tail;
}	t_op_lst;

//linked list operations
t_node	*ft_new_node(int n);
void	ft_clear(t_stack *s);
void	push_bottom(t_stack *s, t_node *node);
void	swap(t_stack *s);
t_node	*pop_bottom(t_stack *s);
t_node	*pop_top(t_stack *s);
void	push_top(t_stack *s, t_node *node);

//push_swap_operations
void	swap_swap(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	rotate_rotate(t_stack *a, t_stack *b);
void	pop_push(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *s);
void	reverse_rotate_rotate(t_stack *a, t_stack *b);

//sorting functions
void	insertion_sort(t_stack *a, t_stack *b, t_op_lst	*ops);

//utils
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
t_op	*link_op_lst(t_op_lst *lst, char *s);
void	ft_print_ops(t_op_lst *ops);





// TODO remove
void print_list(t_stack *a);

#endif
