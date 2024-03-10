/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:38:01 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/01/12 12:04:27 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *string)
{
	size_t	x;

	x = 0;
	while (string[x] != '\0')
		x++;
	return (x);
}

void	ft_putstr(char *s, int *count)
{
	int	n;

	if (!s)
	{
		*count += write(1, "(null)", 6);
		return ;
	}
	n = ft_strlen(s);
	write(1, s, n);
	(*count) += n;
}
