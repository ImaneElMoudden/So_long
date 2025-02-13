CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L/usr/include/minilibx-linux -lmlx_Linux -I/usr/include/minilibx-linux -lXext -lX11 -lm -lz

SRC = so_long.c display_map.c map.c map_helper.c map_helper2.c get_next_line.c error.c clean_exit.c \
	move.c move_directions.c move_directions2.c ft_printf.c ft_printf_utils.c

BONUS = so_long_bonus.c display_map_bonus.c display_images_bonus.c map_bonus.c map_helper_bonus.c map_helper2_bonus.c get_next_line_bonus.c error_bonus.c \
	move_bonus.c move_down_bonus.c move_up_bonus.c move_left_bonus.c move_right_bonus.c move_directions_helper_bonus.c libft_helper_bonus.c clean_exit_bonus.c

OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUS:.c=.o)

NAME = so_long
BONUSNAME = so_long_bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS)

bonus: $(BONUSNAME)

$(BONUSNAME): $(BONUSOBJ)
	$(CC) $(CFLAGS) -o $(BONUSNAME) $(BONUSOBJ) $(MLXFLAGS)

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME) $(BONUSNAME)

re: fclean all

.PHONY: all bonus clean fclean re