/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:08:29 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/24 13:09:55 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *counter)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', counter);
		ft_putchar('2', counter);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-', counter);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, counter);
	}
	ft_putchar('0' + nb % 10, counter);
}
