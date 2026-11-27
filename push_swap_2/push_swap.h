#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "data_structs.h"


//utils
int	ft_atoi(const char *nptr);
int ft_strcmp(const char *s1, const char *s2);

int	ft_parse_input(t_flags *flags, t_stack *a, int ac, char **av);

t_node	*ft_new_node(int n);
void	ft_clear_stack(t_stack *stack);

#endif
