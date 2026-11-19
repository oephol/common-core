#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

t_node	*ft_new_node(int n);
void	ft_clear(t_stack *s);
void	push_top(t_stack *s, t_node *node);
void	push_bottom(t_stack *s, t_node *node);
void	swap(t_stack *s);
t_node	*pop_top(t_stack *s);
t_node	*pop_bottom(t_stack *s);
void	pop_push(t_stack *a, t_stack *b);

#endif
