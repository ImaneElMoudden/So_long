/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:37:43 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:13:56 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *img)
{
	clean_exit(img);
	return (0);
}

void	clean_exit2(t_data *img)
{
	if (img->mlx)
		mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(0);
}

void	clean_exit(t_data *img)
{
	free_array(img->map->grid);
	if (img->wall)
		mlx_destroy_image(img->mlx, img->wall);
	if (img->collectible)
		mlx_destroy_image(img->mlx, img->collectible);
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
	if (img->other)
		mlx_destroy_image(img->mlx, img->other);
	if (img->player_exit)
		mlx_destroy_image(img->mlx, img->player_exit);
	if (img->mlx_win)
		mlx_destroy_window(img->mlx, img->mlx_win);
	clean_exit2(img);
}
