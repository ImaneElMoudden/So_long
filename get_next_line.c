/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:30:08 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/01/31 22:07:37 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *str)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	arr = malloc(j + 1);
	if (!arr)
		return (NULL);
	while (i < j)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*get_next_line(int fd)
{
	char	buffer[100000];
	char	*line;
	char	character;
	int		bytes_read;
	int		i;

	i = 0;
	bytes_read = read(fd, &character, 1);
	while (bytes_read > 0 && character != '\n')
	{
		buffer[i++] = character;
		bytes_read = read(fd, &character, 1);
	}
	if (bytes_read == -1 || (bytes_read == 0 && i == 0))
		return (NULL);
	if (character == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	line = ft_strdup(buffer);
	return (line);
}
