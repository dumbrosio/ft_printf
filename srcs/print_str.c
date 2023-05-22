
#include "ft_printf.h"

int	print_str(char *str)
{
	int	i;

	if (!str)
	{
		str = "(null)";
		i = 6;
	}
	i = 0;
	while (str[i])
	{
		print_char(str[i]);
		i++;
	}
	return (i);
}
