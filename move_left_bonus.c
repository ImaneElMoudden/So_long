/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:10:10 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/13 15:28:03 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left1(t_data *img)
{
	if (img->collectible_counter == img->total_collectibles)
		clean_exit(img);
	else
	{
		img->map->grid[img->player_y][img->player_x] = '0';
		img->map->grid[img->player_y][img->player_x - 1] = 'e';
	}
}

void	move_left2(t_data *img)
{
	img->map->grid[img->player_y][img->player_x - 1] = 'P';
	if (img->map->grid[img->player_y][img->player_x] == 'e')
		img->map->grid[img->player_y][img->player_x] = 'E';
	else
		img->map->grid[img->player_y][img->player_x] = '0';
}

void	move_left(t_data *img)
{
	if (img->map->grid[img->player_y][img->player_x - 1] == '1')
		return ;
	if (img->map->grid[img->player_y][img->player_x - 1] == 'X')
		clean_exit(img);
	if (img->map->grid[img->player_y][img->player_x - 1] == 'C')
	{
		if (img->map->grid[img->player_y][img->player_x] == 'P')
			img->map->grid[img->player_y][img->player_x] = '0';
		else if (img->map->grid[img->player_y][img->player_x] == 'e')
			img->map->grid[img->player_y][img->player_x] = 'E';
		img->map->grid[img->player_y][img->player_x - 1] = 'P';
		img->collectible_counter++;
	}
	else if (img->map->grid[img->player_y][img->player_x - 1] == 'E')
		move_left1(img);
	else
		move_left2(img);
	img->player_x = img->player_x - 1;
	mlx_clear_window(img->mlx, img->mlx_win);
	img->direction = 3;
	display_images(img, img->map);
	print_moves(img);
}
