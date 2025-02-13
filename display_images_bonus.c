/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:33:42 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:34:37 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_player_frame(t_data *img, int y, int x)
{
	if (img->direction == 0)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player, x
			* img->tile_size, y * img->tile_size);
	if (img->direction == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_up, x
			* img->tile_size, y * img->tile_size);
	if (img->direction == 3)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_left, x
			* img->tile_size, y * img->tile_size);
	if (img->direction == 2)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_right, x
			* img->tile_size, y * img->tile_size);
}

void	display_images2(t_data *img, char c, int y, int x)
{
	if (c == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->wall, x
			* img->tile_size, y * img->tile_size);
	else if (c == 'C')
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->collectible[img->frame], x * img->tile_size, y
			* img->tile_size);
	else if (c == 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, x
			* img->tile_size, y * img->tile_size);
	else if (c == 'P')
		display_player_frame(img, y, x);
	else if (c == 'X')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->enemy, x
			* img->tile_size, y * img->tile_size);
	else if (c == 'e')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_exit, x
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
