/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:14 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/23 13:14:15 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	handle_case(va_list args, const char c);
int	print_char(int c);
int	print_str(char *str);
int	print_hex(unsigned long n, char *hex);
int	print_nbr(int n);
int	print_ptr(unsigned long n, char *hex);
int	print_uns(unsigned int n);

#endif
