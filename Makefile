NAME = so_long
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(LIBFT_DIR)/include -I $(MLX_DIR)
LIBRARY = -L $(MLX_DIR) -l $(MLX) -L $(LIBFT_DIR) -l $(LIBFT) \
	-L/usr/X11R6/lib -lX11 -lXext
SRC_DIR = src/
MSRCS = main.c parse_map.c validate_map.c validate_map_helper.c \
	load_texture.c update_per_frame.c draw_screen.c draw_screen_helper.c \
	handle_event.c handle_coord.c utils.c exit.c
MOBJS = $(addprefix $(SRC_DIR), $(MSRCS:.c=.o))
BSRCS = main_bonus.c parse_map.c validate_map.c validate_map_helper.c \
	load_texture.c update_per_frame_bonus.c draw_screen.c draw_screen_helper_bonus.c \
	handle_event_bonus.c handle_coord_bonus.c utils.c exit.c
BOBJS = $(addprefix $(SRC_DIR), $(BSRCS:.c=.o))
LIBFT = ft
LIBFT_DIR = ./lib/libft
MLX_DIR = ./lib/minilibx-linux
MLX = mlx_Darwin

ifdef IS_BONUS
	OBJS = $(BOBJS)
else
	OBJS = $(MOBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBRARY) -framework OpenGL -framework AppKit -o $@

bonus:
	make IS_BONUS=1

.c.o: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(MOBJS) $(BOBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
