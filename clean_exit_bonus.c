/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:22:19 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:34:23 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_exit2(t_data *img)
{
	if (img->other)
		mlx_destroy_image(img->mlx, img->other);
	if (img->enemy)
		mlx_destroy_image(img->mlx, img->enemy);
	if (img->player_exit)
		mlx_destroy_image(img->mlx, img->player_exit);
	if (img->mlx_win)
		mlx_destroy_window(img->mlx, img->mlx_win);
	if (img->mlx)
		mlx_destroy_display(img->mlx);
	ft_free(img->mlx);
	exit(0);
}

void	clean_exit(t_data *img)
{
	free_array(img->map->grid);
	if (img->wall)
		mlx_destroy_image(img->mlx, img->wall);
	if (img->enemies)
		ft_free(img->enemies);
	if (img->collectible[0])
		mlx_destroy_image(img->mlx, img->collectible[0]);
	if (img->collectible[1])
		mlx_destroy_image(img->mlx, img->collectible[1]);
	if (img->collectible[2])
		mlx_destroy_image(img->mlx, img->collectible[2]);
	if (img->player)
		mlx_destroy_image(img->mlx, img->player);
	if (img->player_up)
		mlx_destroy_image(img->mlx, img->player_up);
	if (img->player_left)
		mlx_destroy_image(img->mlx, img->player_left);
	if (img->player_right)
		mlx_destroy_image(img->mlx, img->player_right);
	if (img->exit)
		mlx_destroy_image(img->mlx, img->exit);
	if (img->open_exit)
		mlx_destroy_image(img->mlx, img->open_exit);
	clean_exit2(img);
}
