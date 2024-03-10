/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:07:54 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/01/12 12:02:53 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(size_t n, int *count)
{
	char	str[16];
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	*count += 2;
	if (n == 0)
	{
		ft_putstr("0", count);
		return ;
	}
	while (n != 0)
	{
		str[i] = base[n % 16];
		n /= 16;
		i++;
	}
	while (i-- > 0)
	{
		ft_putchar(str[i], count);
	}
}
