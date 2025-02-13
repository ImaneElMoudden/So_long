/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:16:46 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/10 15:44:00 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (ft_putstr("0x") + ft_printhexa(ptr, 'x'));
}

int	ft_putnbru(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_putchar(n + 48);
	else
	{
		count += ft_putnbru(n / 10);
		count += ft_putchar(n % 10 + 48);
	}
	return (count);
}

int	ft_putnbr(int number)
{
	unsigned int	n;
	int				count;

	count = 0;
	if (number < 0)
	{
		count += ft_putchar('-');
		n = -number;
	}
	else
		n = number;
	if (n < 10)
		count += ft_putchar(n + 48);
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + 48);
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printhexa(unsigned long number, char c)
{
	int	n;

	n = 0;
	if (number >= 16)
		n += ft_printhexa(number / 16, c);
	if (c == 'x')
		n += ft_putchar("0123456789abcdef"[number % 16]);
	else
		n += ft_putchar("0123456789ABCDEF"[number % 16]);
	return (n);
}
