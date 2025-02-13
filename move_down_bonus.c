/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:04:44 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/13 15:27:55 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_down1(t_data *img)
{
	if (img->collectible_counter == img->total_collectibles)
		clean_exit(img);
	else
	{
		img->map->grid[img->player_y][img->player_x] = '0';
		img->map->grid[img->player_y + 1][img->player_x] = 'e';
	}
}

void	move_down2(t_data *img)
{
	img->map->grid[img->player_y + 1][img->player_x] = 'P';
	if (img->map->grid[img->player_y][img->player_x] == 'e')
		img->map->grid[img->player_y][img->player_x] = 'E';
	else
		img->map->grid[img->player_y][img->player_x] = '0';
}

void	move_down(t_data *img)
{
	if (img->map->grid[img->player_y + 1][img->player_x] == '1')
		return ;
	if (img->map->grid[img->player_y + 1][img->player_x] == 'X')
		clean_exit(img);
	if (img->map->grid[img->player_y + 1][img->player_x] == 'C')
	{
		if (img->map->grid[img->player_y][img->player_x] == 'P')
			img->map->grid[img->player_y][img->player_x] = '0';
		else if (img->map->grid[img->player_y][img->player_x] == 'e')
			img->map->grid[img->player_y][img->player_x] = 'E';
		img->map->grid[img->player_y + 1][img->player_x] = 'P';
		img->collectible_counter++;
	}
	else if (img->map->grid[img->player_y + 1][img->player_x] == 'E')
		move_down1(img);
	else
		move_down2(img);
	img->player_y = img->player_y + 1;
	mlx_clear_window(img->mlx, img->mlx_win);
	img->direction = 0;
	display_images(img, img->map);
	print_moves(img);
}
