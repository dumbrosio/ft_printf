
#include "ft_printf.h"

int	print_ptr(unsigned long n, char *hex)
{
	int	i;

	i = 2;
	print_char('0');
	print_char('x');
	i += print_hex(n, hex);
	return (i);
}
