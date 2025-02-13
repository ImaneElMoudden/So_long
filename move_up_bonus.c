/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:15:00 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/13 15:27:11 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up1(t_data *img)
{
	if (img->collectible_counter == img->total_collectibles)
		clean_exit(img);
	else
	{
		img->map->grid[img->player_y][img->player_x] = '0';
		img->map->grid[img->player_y - 1][img->player_x] = 'e';
	}
}

void	move_up2(t_data *img)
{
	img->map->grid[img->player_y - 1][img->player_x] = 'P';
	if (img->map->grid[img->player_y][img->player_x] == 'e')
		img->map->grid[img->player_y][img->player_x] = 'E';
	else
		img->map->grid[img->player_y][img->player_x] = '0';
}

void	move_up(t_data *img)
{
	if (img->map->grid[img->player_y - 1][img->player_x] == '1')
		return ;
	if (img->map->grid[img->player_y - 1][img->player_x] == 'X')
		clean_exit(img);
	if (img->map->grid[img->player_y - 1][img->player_x] == 'C')
	{
		if (img->map->grid[img->player_y][img->player_x] == 'P')
			img->map->grid[img->player_y][img->player_x] = '0';
		else if (img->map->grid[img->player_y][img->player_x] == 'e')
			img->map->grid[img->player_y][img->player_x] = 'E';
		img->map->grid[img->player_y - 1][img->player_x] = 'P';
		img->collectible_counter++;
	}
	else if (img->map->grid[img->player_y - 1][img->player_x] == 'E')
		move_up1(img);
	else
		move_up2(img);
	img->player_y = img->player_y - 1;
	mlx_clear_window(img->mlx, img->mlx_win);
	img->direction = 1;
	display_images(img, img->map);
	print_moves(img);
}

int	handle_key(int key, t_data *img)
{
	if (key == XK_Right)
		move_right(img);
	else if (key == XK_Left)
		move_left(img);
	else if (key == XK_Up)
		move_up(img);
	else if (key == XK_Down)
		move_down(img);
	else if (key == XK_Escape)
		clean_exit(img);
	update_exit_image(img);
	return (0);
}
