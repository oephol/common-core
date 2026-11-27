#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "data_structs.h"


//input utils
int	ft_atoi(const char *nptr);
int ft_strcmp(const char *s1, const char *s2);

//input 
int	ft_parse_input(t_flags *flags, t_stack *a, int ac, char **av);

//node utils
t_node	*ft_new_node(int n);
void	ft_clear_stack(t_stack *stack);

//stack
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
int	ft_push_bottom(t_stack *stack, t_node *node);
void	ft_push_top(t_stack *stack, t_node *node);
t_node	*ft_pop_top(t_stack *stack);
t_node	*ft_pop_bottom(t_stack *stack);

//operations
void	ft_op_sa(t_push_swap *ps);
void	ft_op_sb(t_push_swap *ps);
void	ft_op_ss(t_push_swap *ps);
void	ft_op_pa(t_push_swap *ps);
void	ft_op_pb(t_push_swap *ps);
void	ft_op_ra(t_push_swap *ps);
void	ft_op_rb(t_push_swap *ps);
void	ft_op_rr(t_push_swap *ps);
void	ft_op_rra(t_push_swap *ps);
void	ft_op_rrb(t_push_swap *ps);
void	ft_op_rrr(t_push_swap *ps);

//log operations
t_node	*ft_append_log(t_op_log *log, t_operation op);
void	ft_clear_log(t_op_log *log);

//output
void	ft_print_opretions(t_push_swap *ps, t_flags *flags);
void	ft_count_operatins(t_op_log *log, t_bench *bench);
void	ft_print_int(int x);
void	ft_print_disorder(float x);
void	ft_print_bench(t_push_swap *ps, t_flags *flags);

// utils
void	ft_free_all(t_push_swap *ps, int status);
void	ft_error(t_push_swap *ps);
void	ft_bzero(void *mem, int size);
float	ft_disorder(t_stack *a, t_node *temp1, t_node *temp2);
int		ft_set_strategy(t_flags *flags)

#endif
