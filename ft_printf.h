/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:16:13 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/10 15:42:26 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int number);
int	ft_putnbru(unsigned int n);
int	ft_putptr(unsigned long ptr);
int	ft_printhexa(unsigned long number, char c);

#endif