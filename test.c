#include <unistd.h>

void	ft_print_int(int x)
{
	char	c;

	if (x < 10)
	{
		c = x % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_print_int(x / 10);
		c = x % 10 + '0';
		write(1, &c, 1);
	}
}
void	ft_print_float(float x)
{
	int	n;

	n = (int)x;
	if (n < 10)
		write (1, "0", 1);
	ft_print_int(n);
	write(1, ".", 1);
	n = (x - n) * 100;
	if (n)
		ft_print_int(n);
	else
		write(1, "00", 2);
}

int main(void)
{
	ft_print_float(1);
	write(1, "%\n", 2);
}