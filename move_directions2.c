/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_directions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:08:29 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 02:32:02 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right2(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_right,
		(img->player_x + 1) * img->tile_size, img->player_y * img->tile_size);
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

void	move_right(t_data *img)
{
	if (img->map->grid[img->player_y][img->player_x + 1] == '1')
		return ;
	if (img->map->grid[img->player_y][img->player_x + 1] == 'C')
	{
		img->map->grid[img->player_y][img->player_x + 1] = '0';
		img->collectible_counter++;
	}
	if (img->map->grid[img->player_y][img->player_x + 1] == 'E')
	{
		if (img->collectible_counter == img->total_collectibles)
			clean_exit(img);
		else
		{
			img->map->grid[img->player_y][img->player_x + 1] = 'e';
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_exit,
				(img->player_x + 1) * img->tile_size, img->player_y
				* img->tile_size);
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->other,
				img->player_x * img->tile_size, img->player_y * img->tile_size);
		}
	}
	else
		move_right2(img);
	img->player_x = img->player_x + 1;
	ft_printf("moves: %d\n", ++img->moves_counter);
}

void	move_left2(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_left,
		(img->player_x - 1) * img->tile_size, img->player_y * img->tile_size);
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

void	move_left(t_data *img)
{
	if (img->map->grid[img->player_y][img->player_x - 1] == '1')
		return ;
	if (img->map->grid[img->player_y][img->player_x - 1] == 'C')
	{
		img->map->grid[img->player_y][img->player_x - 1] = '0';
		img->collectible_counter++;
	}
	if (img->map->grid[img->player_y][img->player_x - 1] == 'E')
	{
		if (img->collectible_counter == img->total_collectibles)
			clean_exit(img);
		else
		{
			img->map->grid[img->player_y][img->player_x - 1] = 'e';
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->player_exit,
				(img->player_x - 1) * img->tile_size, img->player_y
				* img->tile_size);
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->other,
				img->player_x * img->tile_size, img->player_y * img->tile_size);
		}
	}
	else
		move_left2(img);
	img->player_x = img->player_x - 1;
	ft_printf("moves: %d\n", ++img->moves_counter);
}
