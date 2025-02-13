/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:10:24 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:36:31 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_collectibles_and_enemies(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map->grid[i])
	{
		j = 0;
		while (img->map->grid[i][j])
		{
			if (img->map->grid[i][j] == 'C')
				img->total_collectibles++;
			if (img->map->grid[i][j] == 'X')
				img->enemy_count++;
			j++;
		}
		i++;
	}
}

void	fill_enemy_struct(t_data *img)
{
	int	i;
	int	x;
	int	y;

	img->enemies = malloc(sizeof(t_enemy) * img->enemy_count);
	if (!img->enemies)
		clean_exit(img);
	i = 0;
	y = 0;
	while (img->map->grid[y])
	{
		x = 0;
		while (img->map->grid[y][x])
		{
			if (img->map->grid[y][x] == 'X')
			{
				img->enemies[i].x = x;
				img->enemies[i].y = y;
				img->enemies[i].direction = 1;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	initialize_struct(t_data *img)
{
	img->collectible_counter = 0;
	img->total_collectibles = 0;
	img->enemy_count = 0;
	count_collectibles_and_enemies(img);
	img->moves_counter = 0;
	img->frame = 0;
	img->i = 0;
	img->j = 0;
	img->direction = 0;
	fill_enemy_struct(img);
	img->mlx = NULL;
	img->mlx_win = NULL;
	img->wall = NULL;
	img->player = NULL;
	img->player_left = NULL;
	img->player_right = NULL;
	img->player_up = NULL;
	img->collectible[0] = NULL;
	img->collectible[1] = NULL;
	img->collectible[2] = NULL;
	img->exit = NULL;
	img->open_exit = NULL;
	img->other = NULL;
	img->enemy = NULL;
	img->player_exit = NULL;
}

int	main(int ac, char **av)
{
	t_map	map;
	t_data	img;

	if (ac != 2)
		return (0);
	map.c = 0;
	map.e = 0;
	map.p = 0;
	map.c2 = 0;
	map.e2 = 0;
	get_map(av[1], &map);
	img.map = &map;
	initialize_struct(&img);
	initialize_mlx(&map, &img);
	display_map_on_window(&img);
	display_images(&img, &map);
	move_images(&img);
	mlx_hook(img.mlx_win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
}
