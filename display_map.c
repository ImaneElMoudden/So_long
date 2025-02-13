/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:34:51 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 20:36:50 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_images2(t_data *img, char c, int y, int x)
{
	if (c == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->wall, x
			* img->tile_size, y * img->tile_size);
	else if (c == 'C')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->collectible, x
			* img->tile_size, y * img->tile_size);
	else if (c == 'E')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, x
			* img->tile_size, y * img->tile_size);
	}
	else if (c == 'P')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player, x
			* img->tile_size, y * img->tile_size);
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->other, x
			* img->tile_size, y * img->tile_size);
}

void	display_images(t_data *img, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			display_images2(img, map->grid[y][x], y, x);
			x++;
		}
		y++;
	}
}

void	check_display_error(t_data *img)
{
	if (!img->wall || !img->collectible || !img->exit || !img->open_exit
		|| !img->player || !img->player_left || !img->player_right
		|| !img->player_up || !img->other || !img->player_exit)
	{
		write(2, "Error\nFailed to load XPM images.\n", 33);
		clean_exit(img);
	}
}

void	display_map_on_window(t_data *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx, "textures/wall_16.xpm",
			&img->img_width, &img->img_height);
	img->collectible = mlx_xpm_file_to_image(img->mlx,
			"textures/collectible3_16.xpm", &img->img_width, &img->img_height);
	img->exit = mlx_xpm_file_to_image(img->mlx, "textures/exit_16.xpm",
			&img->img_width, &img->img_height);
	img->open_exit = mlx_xpm_file_to_image(img->mlx,
			"textures/exit_open_16.xpm", &img->img_width, &img->img_height);
	img->player = mlx_xpm_file_to_image(img->mlx, "textures/player_16.xpm",
			&img->img_width, &img->img_height);
	img->player_up = mlx_xpm_file_to_image(img->mlx,
			"textures/player_up_16.xpm", &img->img_width, &img->img_height);
	img->player_right = mlx_xpm_file_to_image(img->mlx,
			"textures/player_right_16.xpm", &img->img_width, &img->img_height);
	img->player_left = mlx_xpm_file_to_image(img->mlx,
			"textures/player_left_16.xpm", &img->img_width, &img->img_height);
	img->other = mlx_xpm_file_to_image(img->mlx, "textures/other_16.xpm",
			&img->img_width, &img->img_height);
	img->player_exit = mlx_xpm_file_to_image(img->mlx,
			"textures/player_exit_16.xpm", &img->tile_size, &img->tile_size);
	check_display_error(img);
}

void	initialize_mlx(t_map *map, t_data *img)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		free_array_write_error(map->grid, "Failed to initialize mlx.");
	img->tile_size = 32;
	img->win_width = map->width * img->tile_size;
	img->win_height = map->height * img->tile_size;
	img->mlx_win = mlx_new_window(img->mlx, img->win_width, img->win_height,
			"so_long");
	if (!img->mlx_win)
		free_array_write_error(map->grid, "Failed to create a new window.");
}
