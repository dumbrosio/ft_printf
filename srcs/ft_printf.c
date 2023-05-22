
#include "ft_printf.h"
#include <stdarg.h>

int	handle_case(va_list args, const char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += print_char(va_arg(args, int));
	else if (c == 's')
		count += print_str(va_arg(args, char *));
	else if (c == 'p')
		count += print_ptr(va_arg(args, unsigned long), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		count += print_nbr(va_arg(args, int));
	else if (c == 'u')
		count += print_uns(va_arg(args, unsigned int));
	else if (c == 'x')
		count += print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += handle_case(args, str[i]);
		}
		else
			count += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
