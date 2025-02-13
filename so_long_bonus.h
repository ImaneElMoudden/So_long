/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudd <ielmoudd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:01:57 by ielmoudd          #+#    #+#             */
/*   Updated: 2025/02/13 16:15:37 by ielmoudd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int		c2;
	int		e2;
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

// get_next_line
char		*get_next_line(int fd);
char		*ft_strdup(char *str);

typedef struct s_enemy
{
	int		x;
	int		y;
	int		direction;
}			t_enemy;

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
	void	*collectible[3];
	void	*exit;
	void	*open_exit;
	void	*other;
	void	*enemy;
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
	int		frame;
	int		i;
	int		j;
	int		direction;
	t_map	*map;
	t_enemy	*enemies;
	int		enemy_count;
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
int			handle_key(int key, t_data *img);
void		update_exit_image(t_data *img);
void		print_moves(t_data *img);

// libft
char		*ft_itoa(int n);
char		*ft_strjoin(char *s1, char *s2);

// error
void		ft_free(void *arg);
void		free_array(char **arr);
void		free_array_write_error(char **arr, char *str);
void		exit_write_error(char *str);
void		clean_exit(t_data *img);
void		free_str_write_error(char *s, char *str);

#endif