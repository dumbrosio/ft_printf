/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:33 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/23 13:23:17 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
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

	if (!format)
		return (0);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_case(args, format[i]);
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
