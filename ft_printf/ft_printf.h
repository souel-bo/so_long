/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:26:59 by souel-bo          #+#    #+#             */
/*   Updated: 2024/11/24 13:56:02 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_put_unsigned(unsigned int nb, int *counter);
void	ft_puthex(unsigned long nb, char *base, int *counter);
void	ft_putnbr(int nb, int *counter);
void	ft_putptr(unsigned long nb, int *counter);

#endif