/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:07:29 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:35:41 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_map_file(char *str)
{
	char	*ptr;

	if (ft_strlen(str) <= 4)
		exit_write_error("Invalid map file path: use a .ber file");
	ptr = ft_strrchr(str, '.');
	if (!ptr)
		exit_write_error("Invalid map file path: use a .ber file");
	if (*(ptr - 1) == '/')
		exit_write_error("Invalid map file path: use a .ber file");
	if (ft_strncmp(ptr, ".ber", 4))
		exit_write_error("Invalid map file path: use a .ber file");
}
