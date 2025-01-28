/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:39:13 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/26 10:50:22 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put(const char *format, va_list list, int *counter)
{
	if (*format == 'c')
		ft_putchar((char)va_arg(list, int), counter);
	else if (*format == 's')
		ft_putstr(va_arg(list, char *), counter);
	else if (*format == 'p')
		ft_putptr(va_arg(list, unsigned long), counter);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(list, int), counter);
	else if (*format == 'u')
		ft_put_unsigned(va_arg(list, unsigned int), counter);
	else if (*format == 'x')
		ft_puthex(va_arg(list, unsigned int), "0123456789abcdef", counter);
	else if (*format == 'X')
		ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF", counter);
	else if (*format == '%')
		ft_putchar('%', counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		counter;

	if (!format)
		return (0);
	va_start(list, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_put(format, list, &counter);
		}
		else
			ft_putchar(*format, &counter);
		format++;
	}
	va_end(list);
	return (counter);
}
