/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:14:53 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/23 13:22:40 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_uns(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += print_uns(n / 10);
	i += print_char(n % 10 + 48);
	return (i);
}
