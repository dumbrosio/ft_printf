/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:39:04 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/16 19:39:41 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

char	*ft_char(char *s, unsigned int number, int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*s;
	int		len;
	unsigned int	number;
	int		sign;

	sign = 1;
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = ft_char(s, number, len);
	return (s);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len ++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (hex_len(num));
}

int	ft_conversion(va_list vl, const char format)
{
	int	char_printed;

	char_printed = 0;
	if (format == 'c')
		char_printed += ft_putchar(va_arg(vl, int));
	else if (format == 's')
		char_printed += ft_putstr(va_arg(vl, char *));
	else if (format == 'd')
		char_printed += ft_putnbr(va_arg(vl, int));
	else if (format == 'x')
		char_printed += ft_print_hex(va_arg(vl, unsigned int), format);
	else if (format == '%')
		char_printed += ft_putchar('%');
	return (char_printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	vl;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_printed += ft_conversion(vl, format[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(format[i]);
		i++;
	}
	va_end(vl);
	return (char_printed);
}
