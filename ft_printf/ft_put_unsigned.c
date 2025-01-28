/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:57:43 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/24 12:58:29 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned(unsigned int nb, int *counter)
{
	if (nb >= 10)
		ft_put_unsigned(nb / 10, counter);
	ft_putchar(nb % 10 + '0', counter);
}
