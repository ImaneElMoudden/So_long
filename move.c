/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:56:32 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/11 23:42:29 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_and_exit_pos(t_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (img->map->grid[y])
	{
		x = 0;
		while (img->map->grid[y][x])
		{
			if (img->map->grid[y][x] == 'P')
			{
				img->player_x = x;
				img->player_y = y;
			}
			else if (img->map->grid[y][x] == 'E')
			{
				img->exit_x = x;
				img->exit_y = y;
			}
			x++;
		}
		y++;
	}
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

void	move_images(t_data *img)
{
	find_player_and_exit_pos(img);
	mlx_hook(img->mlx_win, 2, 1L << 0, handle_key, img);
}
