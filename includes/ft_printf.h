
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	handle_case(va_list args, const char c);
int	print_char(int c);
int	print_str(char *str);
int	print_hex(unsigned long n, char *hex);
int	print_nbr(int n);
int	print_ptr(unsigned long n, char *hex);
int	print_uns(unsigned int n);
#endif
