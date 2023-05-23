/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:47 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/23 13:23:01 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_ptr(unsigned long n, char *hex)
{
	int	i;

	i = 2;
	print_char('0');
	print_char('x');
	i += print_hex(n, hex);
	return (i);
}
