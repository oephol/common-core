#include "./../../push_swap.h"

void	ft_bzero(void *mem, int size)
{
	int				i;
	unsigned char	*p;

	p = mem;
	i = 0;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
}
