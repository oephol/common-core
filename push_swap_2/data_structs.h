#ifndef DATA_STRUCTS_H
# define DATA_STRUCTS_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

typedef enum e_operation
{
    op_sa,
    op_sb,
    op_ss,
    op_pa,
    op_pb,
    op_ra,
    op_rb,
    op_rr,
    op_rra,
    op_rrb,
    op_rrr
}   t_operation;

typedef struct s_op_node
{
	t_operation			operation;
	struct s_op_node	*next;
}	t_op_node;

typedef	struct s_op_log
{
	t_op_node	*head;
	t_op_node	*tail;
}	t_op_log;

typedef struct s_push_swap
{
	t_stack		a;
	t_stack		b;
	t_op_log	log;
}	t_push_swap;

typedef struct s_bench_info
{
	float		disorder;
	int			strategy;
	int			total_ops;
	t_operation	operations[11];
}	t_bench;

typedef struct s_flags
{
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	int		bench;
	t_bench	bench_info;
}	t_flags;

#endif