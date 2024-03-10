/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:08:28 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/01/12 11:55:22 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long long n, int *count)
{
	if (n < 0)
	{
		ft_putchar('-', count);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	ft_putchar(n % 10 + '0', count);
}
