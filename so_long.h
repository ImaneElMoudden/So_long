/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:10:50 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/12 21:16:48 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		c;
	int		e;
	int		p;
}			t_map;

typedef struct s_player
{
	int		py;
	int		px;
}			t_player;

// map
void		get_map(char *str, t_map *map);
void		check_valid_path(t_map *map);
int			ft_strlen(char *str);
void		check_map_file(char *str);

// printf
int			ft_printf(const char *format, ...);

// get_next_line
char		*get_next_line(int fd);
char		*ft_strdup(char *str);

// mlx
typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*player;
	void	*player_up;
	void	*player_right;
	void	*player_left;
	void	*collectible;
	void	*exit;
	void	*open_exit;
	void	*other;
	void	*player_exit;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	int		tile_size;
	int		player_y;
	int		player_x;
	int		collectible_counter;
	int		total_collectibles;
	int		moves_counter;
	int		exit_x;
	int		exit_y;
	t_map	*map;
}			t_data;

void		initialize_mlx(t_map *map, t_data *img);
void		display_map_on_window(t_data *img);
void		display_images(t_data *img, t_map *map);
int			close_window(t_data *img);

// move
void		move_images(t_data *img);
void		move_right(t_data *img);
void		move_left(t_data *img);
void		move_up(t_data *img);
void		move_down(t_data *img);
void		update_exit_image(t_data *img);

// error
void		free_array(char **arr);
void		free_str_write_error(char *s, char *str);
void		free_array_write_error(char **arr, char *str);
void		exit_write_error(char *str);
void		clean_exit(t_data *img);

#endif