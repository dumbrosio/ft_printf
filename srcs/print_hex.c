/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:42 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/23 13:23:10 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_hex(unsigned long n, char *hex)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += print_hex(n / 16, hex);
	i += print_char(hex[n % 16]);
	return (i);
}
