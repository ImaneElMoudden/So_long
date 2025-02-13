/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:10:24 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:16:53 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_collectibles(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map->grid[i])
	{
		j = 0;
		while (img->map->grid[i][j])
		{
			if (img->map->grid[i][j] == 'C')
				img->total_collectibles++;
			j++;
		}
		i++;
	}
}

void	initialize_struct(t_data *img, t_map *map)
{
	img->collectible_counter = 0;
	img->total_collectibles = 0;
	img->map = map;
	count_collectibles(img);
	img->moves_counter = 0;
	img->mlx = NULL;
	img->mlx_win = NULL;
	img->wall = NULL;
	img->player = NULL;
	img->player_left = NULL;
	img->player_right = NULL;
	img->player_up = NULL;
	img->collectible = NULL;
	img->exit = NULL;
	img->open_exit = NULL;
	img->other = NULL;
	img->player_exit = NULL;
	img->player_y = 0;
	img->player_x = 0;
	img->exit_x = 0;
	img->exit_y = 0;
}

int	main(int ac, char **av)
{
	t_map	map;
	t_data	img;

	if (ac != 2)
		return (0);
	map.c = 0;
	map.e = 0;
	map.p = 0;
	get_map(av[1], &map);
	initialize_struct(&img, &map);
	initialize_mlx(&map, &img);
	display_map_on_window(&img);
	display_images(&img, &map);
	move_images(&img);
	mlx_hook(img.mlx_win, 17, 0, close_window, &img);
	mlx_loop(img.mlx);
}
