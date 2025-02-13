/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:13:05 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:34:51 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(void *arg)
{
	if (arg)
		free(arg);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
}

void	free_array_write_error(char **arr, char *str)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	ft_free(arr);
	exit_write_error(str);
}

void	free_str_write_error(char *s, char *str)
{
	write(2, "Error\n", 6);
	if (s)
		free(s);
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	exit(1);
}

void	exit_write_error(char *str)
{
	write(2, "Error\n", 6);
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	exit(1);
}
