/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:31:45 by aaizenbe          #+#    #+#             */
/*   Updated: 2024/01/12 12:15:46 by aaizenbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_type_checker(char str, va_list *args, int *count)
{
	if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(*args, int), count);
	else if (str == 's')
		ft_putstr(va_arg(*args, char *), count);
	else if (str == 'c')
		ft_putchar(va_arg(*args, int), count);
	else if (str == 'p')
		ft_pointer(va_arg(*args, size_t), count);
	else if (str == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), count);
	else if (str == 'x' || str == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), str, count);
	else if (str == '%')
		ft_putchar('%', count);
	else
		(*count)--;
}

int	ft_printf(char const *str, ...)
{
	va_list	args; // es una lista de argumentos que se pasan a la funcion
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_type_checker(str[i], &args, &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
