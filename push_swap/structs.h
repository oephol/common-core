#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_node
{
	int				n;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_op_node
{
	char				*operation;
	struct s_op_node	*next;
}	t_op_node;

typedef	struct s_op_list
{
	t_op_node	*head;
	t_op_node	*tail;
}	t_op_list;

typedef struct s_ops_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops_count;

typedef struct s_bench_info
{
	float		disorder;
	int			strategy;
	int			total_ops;
	t_ops_count	ops_count;
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