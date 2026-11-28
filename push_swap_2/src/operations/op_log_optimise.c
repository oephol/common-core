#include "./../../push_swap.h"

int	ft_optimise_swap(t_op_log *log, t_operation *op)
{
	t_operation	prev_op;

	if (!log->tail)
		return (1);
	prev_op = log->tail->operation;
	if (prev_op != op_sa && prev_op != op_sb && prev_op != op_ss)
		return (1);
	ft_delone_op(log, log->tail);
	if ((*op == op_sa && prev_op == op_sb) || (*op == op_sb && prev_op == op_sa))
		*op = op_ss;
	else if ((*op == op_sa && prev_op == op_ss))
		*op = op_sb;
	else if ((*op == op_sb && prev_op == op_ss))
		*op = op_sa;
	else
		return (0);
	return(1);
}

int	ft_optimise_push(t_op_log *log, t_operation op)
{
	t_operation	prev_op;

	if (!log->tail)
		return (1);
	prev_op = log->tail->operation;
	if ((op == op_pb && prev_op == op_pa) || (op == op_pa && prev_op == op_pb))
	{
		ft_delone_op(log, log->tail);
		return (0);
	}
	return(1);
}

int	ft_optimise_rotate(t_op_log *log, t_operation *op)
{
	t_operation	prev_op;

	if (!log->tail)
		return (1);
	prev_op = log->tail->operation;
	if ((*op == op_ra && prev_op == op_rb) || (*op == op_rb && prev_op == op_ra))
	{
		ft_delone_op(log, log->tail);
		*op = op_rr;
	}
	return(1);
}

int	ft_optimise_rev_rot(t_op_log *log, t_operation *op)
{
	t_operation	prev_op;

	if (!log->tail)
		return (1);
	prev_op = log->tail->operation;
	if ((*op == op_rra && prev_op == op_rrb) || (*op == op_rrb && prev_op == op_rra))
	{
		ft_delone_op(log, log->tail);
		*op = op_rrr;
	}
	return(1);
}
