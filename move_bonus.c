/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:36:14 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:36:00 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_player_pos(t_data *img)
{
	img->player_y = 0;
	while (img->map->grid[img->player_y])
	{
		img->player_x = 0;
		while (img->map->grid[img->player_y][img->player_x])
		{
			if (img->map->grid[img->player_y][img->player_x] == 'P')
			{
				return ;
			}
			(img->player_x)++;
		}
		(img->player_y)++;
	}
}

int	display_animation(t_data *img)
{
	int	y;
	int	x;

	if (img->i < 50000)
	{
		img->i++;
		return (0);
	}
	img->i = 0;
	img->frame = (img->frame + 1) % 3;
	y = 0;
	while (img->map->grid[y])
	{
		x = 0;
		while (img->map->grid[y][x])
		{
			if (img->map->grid[y][x] == 'C')
				mlx_put_image_to_window(img->mlx, img->mlx_win,
					img->collectible[img->frame], x * img->tile_size, y
					* img->tile_size);
			x++;
		}
		y++;
	}
	return (0);
}

void	move_images(t_data *img)
{
	find_player_pos(img);
	mlx_hook(img->mlx_win, 2, 1L << 0, handle_key, img);
	mlx_loop_hook(img->mlx, display_animation, img);
}
