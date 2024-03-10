/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:07:50 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/01/12 12:01:16 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_hexadecimal(unsigned int n, char c, int *count)
{
	unsigned int un;
	char *base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	un = n;
	if (un >= 16)
		ft_hexadecimal(un / 16, c, count);
	ft_putchar(base[un % 16], count);
}

