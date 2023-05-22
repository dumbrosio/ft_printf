
#include "ft_printf.h"

int	print_uns(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += print_uns(n / 10);
	i += print_char(n % 10 + 48);
	return (i);
}
