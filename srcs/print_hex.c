
#include "ft_printf.h"

int	print_hex(unsigned long n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += print_hex(n / 16, hex);
	i += print_char(hex[n % 16]);
	return (i);
}
