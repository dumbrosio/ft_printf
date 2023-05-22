#include "ft_printf.h"

int	print_nbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			print_str("-2147483648");
			return (11);
		}
	i += print_char('-');
	n = -n;
	}
	if (n > 9)
		i += print_nbr(n / 10);
	i += print_char(n % 10 + 48);
	return (i);
}
