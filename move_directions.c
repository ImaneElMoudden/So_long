/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:54 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 02:15:52 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_exit_image(t_data *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < img->map->height)
	{
		x = 0;
		while (x < img->map->width)
		{
			if (img->map->grid[y][x] == 'E')
			{
				if (img->collectible_counter == img->total_collectibles)
					mlx_put_image_to_window(img->mlx, img->mlx_win,
						img->open_exit, x * img->tile_size, y * img->tile_size);
				else
					mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, x
						* img->tile_size, y * img->tile_size);
			}
			x++;
		}
		y++;
	}
}

void	move_up2(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_up,
		img->player_x * img->tile_size, (img->player_y - 1) * img->tile_size);
	if (img->map->grid[img->player_y][img->player_x] == 'e')
	{
		img->map->grid[img->player_y][img->player_x] = 'E';
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, img->player_x
			* img->tile_size, img->player_y * img->tile_size);
	}
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->other,
			img->player_x * img->tile_size, img->player_y * img->tile_size);
}

void	move_up(t_data *img)
{
	if (img->map->grid[img->player_y - 1][img->player_x] == '1')
		return ;
	if (img->map->grid[img->player_y - 1][img->player_x] == 'C')
	{
		img->map->grid[img->player_y - 1][img->player_x] = '0';
		img->collectible_counter++;
	}
	if (img->map->grid[img->player_y - 1][img->player_x] == 'E')
	{
		if (img->collectible_counter == img->total_collectibles)
			clean_exit(img);
		else
		{
			img->map->grid[img->player_y - 1][img->player_x] = 'e';
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_exit,
				img->player_x * img->tile_size, (img->player_y - 1)
				* img->tile_size);
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->other,
				img->player_x * img->tile_size, img->player_y * img->tile_size);
		}
	}
	else
		move_up2(img);
	img->player_y = img->player_y - 1;
	ft_printf("moves: %d\n", ++img->moves_counter);
}

void	move_down2(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->player, img->player_x
		* img->tile_size, (img->player_y + 1) * img->tile_size);
	if (img->map->grid[img->player_y][img->player_x] == 'e')
	{
		img->map->grid[img->player_y][img->player_x] = 'E';
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, img->player_x
			* img->tile_size, img->player_y * img->tile_size);
	}
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->other,
			img->player_x * img->tile_size, img->player_y * img->tile_size);
}

void	move_down(t_data *img)
{
	if (img->map->grid[img->player_y + 1][img->player_x] == '1')
		return ;
	if (img->map->grid[img->player_y + 1][img->player_x] == 'C')
	{
		img->map->grid[img->player_y + 1][img->player_x] = '0';
		img->collectible_counter++;
	}
	if (img->map->grid[img->player_y + 1][img->player_x] == 'E')
	{
		if (img->collectible_counter == img->total_collectibles)
			clean_exit(img);
		else
		{
			img->map->grid[img->player_y + 1][img->player_x] = 'e';
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_exit,
				img->player_x * img->tile_size, (img->player_y + 1)
				* img->tile_size);
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->other,
				img->player_x * img->tile_size, img->player_y * img->tile_size);
		}
	}
	else
		move_down2(img);
	img->player_y = img->player_y + 1;
	ft_printf("moves: %d\n", ++img->moves_counter);
}
