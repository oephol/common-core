#include <unistd.h>

void	ft_print_int(int x)
{
	char	c;

	if (x == 100)
		write (2, "100", 3);
	else
	{
		c = x / 10 + '0';
		write(1, &c, 1);
		c = x % 10 + '0';
		write(1, &c, 1);
	}
}
void	ft_print_float(float x)
{
	int	n;

	n = (int)x;
	ft_print_int(n);
	write(1, ".", 1);
	n = (x - n) * 100;
	ft_print_int(n);
}

int main(void)
{
	ft_print_float(7.5);
	write(1, "%%\n", 2);
}