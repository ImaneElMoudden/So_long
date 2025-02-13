/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:16:26 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/06 16:00:46 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (*s)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}

static int	helper_function(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr((unsigned long)va_arg(args, void *)));
	else if ((c == 'd') || (c == 'i'))
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbru(va_arg(args, unsigned int)));
	else if ((c == 'x') || (c == 'X'))
		return (ft_printhexa(va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		a;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			a = helper_function(*format, args);
			if (a == -1)
				return (-1);
			i += a;
		}
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}
