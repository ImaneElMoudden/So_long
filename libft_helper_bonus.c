/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:27:54 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:35:14 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;
	size_t	i;

	len = ft_intlen(n);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (n == 0)
		p[0] = '0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	p[len] = '\0';
	i = len - 1;
	while (n)
	{
		p[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	char	*st;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = malloc((l1 + l2 + 1) * sizeof(char));
	if (!p)
		return (NULL);
	st = p;
	while (*s1)
	{
		*p = *s1;
		p++;
		s1++;
	}
	while (*s2)
	{
		*p = *s2;
		p++;
		s2++;
	}
	*p = '\0';
	return (st);
}
