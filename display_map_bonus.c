/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:07:00 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:34:43 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_data *img)
{
	clean_exit(img);
	return (0);
}

void	display_and_check_error(t_data *img)
{
	img->player_exit = mlx_xpm_file_to_image(img->mlx,
			"textures/player_exit_16.xpm", &img->tile_size, &img->tile_size);
	if (!img->wall || !img->collectible[0] || !img->collectible[1]
		|| !img->collectible[2] || !img->exit || !img->open_exit || !img->player
		|| !img->player_left || !img->player_right || !img->player_up
		|| !img->other || !img->enemy || !img->player_exit)
	{
		write(2, "Error\nFailed to load XPM images.\n", 33);
		clean_exit(img);
	}
}

void	display_map_on_window(t_data *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx, "textures/wall_16.xpm",
			&img->img_width, &img->img_height);
	img->collectible[0] = mlx_xpm_file_to_image(img->mlx,
			"textures/collectible1_16.xpm", &img->img_width, &img->img_height);
	img->collectible[1] = mlx_xpm_file_to_image(img->mlx,
			"textures/collectible2_16.xpm", &img->img_width, &img->img_height);
	img->collectible[2] = mlx_xpm_file_to_image(img->mlx,
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
	img->enemy = mlx_xpm_file_to_image(img->mlx, "textures/enemy_16.xpm",
			&img->img_width, &img->img_height);
	display_and_check_error(img);
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
