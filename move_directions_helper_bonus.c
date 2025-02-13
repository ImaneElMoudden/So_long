/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_directions_helper_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:26:44 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:36:10 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	print_moves(t_data *img)
{
	char	*s;
	char	*s2;

	img->moves_counter++;
	s2 = ft_itoa(img->moves_counter);
	s = ft_strjoin("moves count: ", s2);
	mlx_string_put(img->mlx, img->mlx_win, 16, 16, 0xFFFFFFFF, s);
	free(s);
	free(s2);
}
