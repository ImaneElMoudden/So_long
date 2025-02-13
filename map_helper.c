/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:02:01 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/11 22:50:23 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_grid(t_map *map)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * (map->height + 1));
	if (!arr)
		free_array_write_error(map->grid, NULL);
	i = 0;
	while (map->grid[i])
	{
		arr[i] = ft_strdup(map->grid[i]);
		if (!arr[i])
		{
			free_array(arr);
			free_array_write_error(map->grid, NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	find_player_position(t_map *map, int *y, int *x)
{
	(*y) = 0;
	while (map->grid[*y])
	{
		(*x) = 0;
		while (map->grid[*y][*x])
		{
			if (map->grid[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	flood_fill(char **arr, t_map *map, int y, int x)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (arr[y][x] == '1' || arr[y][x] == 'V')
		return ;
	arr[y][x] = 'V';
	flood_fill(arr, map, y, x - 1);
	flood_fill(arr, map, y, x + 1);
	flood_fill(arr, map, y + 1, x);
	flood_fill(arr, map, y - 1, x);
}

void	check_valid_path(t_map *map)
{
	char	**arr;
	int		y;
	int		x;

	arr = duplicate_grid(map);
	find_player_position(map, &y, &x);
	flood_fill(arr, map, y, x);
	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (!(arr[y][x] == '1' || arr[y][x] == '0' || arr[y][x] == 'V'
					|| arr[y][x] == '\n'))
			{
				free_array(arr);
				free_array_write_error(map->grid, "Invalid path.");
			}
			x++;
		}
		y++;
	}
	free_array(arr);
}
