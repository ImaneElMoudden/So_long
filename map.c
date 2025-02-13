/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:01:47 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/13 16:40:32 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_entities(t_map *map, char c)
{
	if (c == 'C')
		map->c++;
	else if (c == 'E')
		map->e++;
	else if (c == 'P')
		map->p++;
}

void	check_valid_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j] && map->grid[i][j] != '\n')
		{
			if (((i == 0 || i == (map->height - 1) || j == 0 || j == (map->width
							- 1)) && (map->grid[i][j] != '1'))
				|| (map->grid[i][j] != 'C' && map->grid[i][j] != 'E'
					&& map->grid[i][j] != 'P' && map->grid[i][j] != '1'
					&& map->grid[i][j] != '0'))
				free_array_write_error(map->grid,
					"The map contains an invalid character.");
			count_entities(map, map->grid[i][j]);
			j++;
		}
		i++;
	}
	if (map->e != 1 || map->p != 1 || map->c == 0)
		free_array_write_error(map->grid,
			"You need one E, one P and at least one C.");
}

void	alloc_map(char *str, t_map *map)
{
	int	fd;
	int	i;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit_write_error("Can't open file!");
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	i = 0;
	while (1)
	{
		map->grid[i] = get_next_line(fd);
		if (!map->grid[i])
			break ;
		i++;
	}
	map->grid[i] = NULL;
	close(fd);
}

void	read_and_check_map(char *str, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit_write_error("Can't open file!");
	line = get_next_line(fd);
	if (!line || !ft_strlen(line))
		free_str_write_error(line, "Empty file, or empty lines!");
	map->width = ft_strlen(line);
	map->height = 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (map->width != ft_strlen(line))
		{
			free(line);
			exit_write_error("Map not rectangular, (check for empty lines)");
		}
		map->height++;
	}
	close(fd);
}

void	get_map(char *str, t_map *map)
{
	check_map_file(str);
	read_and_check_map(str, map);
	alloc_map(str, map);
	check_valid_map(map);
	check_valid_path(map);
}
