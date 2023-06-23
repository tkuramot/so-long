# NAME = so_long
# CFLAGS = -Wall -Wextra -Werror
# INCLUDE = -I $(LIBFT_PATH)/include -I $(MLX_PATH) -I src
# LIBRARY = -L $(MLX_PATH) -l $(MLX) -L $(LIBFT_PATH) -l $(LIBFT) \
# 	-L/usr/X11R6/lib -lX11 -lXext
# SRCS = main.c map_parser.c map_validator.c map_validator_helper.c \
# 	graphic_utils.c
# OBJS = $(SRCS:.c=.o)
# LIBFT = ft
# LIBFT_PATH = lib/libft
# MLX_PATH = lib/mlx
# MLX = mlx

# all: $(NAME)

# $(NAME): $(addprefix src/, $(OBJS))
# 	make bonus -C $(LIBFT_PATH)
# 	make -C $(MLX_PATH)
# 	cp $(MLX_PATH)/libmlx.dylib .
# 	$(CC) $(CFLAGS) $(addprefix src/, $(OBJS)) $(INCLUDE) $(LIBRARY) -framework OpenGL -framework AppKit -o $@

# .c.o: $(addprefix src/, $(OBJS))
# 	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# clean:
# 	make -C $(LIBFT_PATH) clean
# 	make -C $(MLX_PATH) clean
# 	$(RM) $(addprefix src/, $(OBJS)) libmlx.dylib

# fclean: clean
# 	make -C $(LIBFT_PATH) fclean
# 	$(RM) $(NAME)

# re: fclean all

# test: $(NAME)
# 	./$(NAME)

# .PHONY: bonus clean fclean re all

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(LIBFT_DIR)/include -I $(MLX_DIR)
LIBRARY = -L $(MLX_DIR) -l $(MLX) -L $(LIBFT_DIR) -l $(LIBFT) \
	-L/usr/X11R6/lib -lX11 -lXext
SRC_DIR = src/
MSRCS = main.c parse_map.c validate_map.c validate_map_helper.c \
	load_texture.c update_per_frame.c draw_screen.c draw_screen_helper.c \
	handle_event.c handle_coord.c utils.c exit.c
MOBJS = $(addprefix $(OBJ_DIR), $(MSRCS:.c=.o))
BSRCS = main.c parse_map.c validate_map.c validate_map_helper.c \
	load_texture.c update_per_frame_bonus.c draw_screen.c draw_screen_helper_bonus.c \
	handle_event_bonus.c handle_coord_bonus.c move_enemy_bonus.c utils.c exit.c
BOBJS = $(addprefix $(OBJ_DIR), $(BSRCS:.c=.o))
LIBFT = ft
LIBFT_DIR = ./lib/libft
MLX_DIR = ./lib/minilibx-linux
MLX = mlx_Darwin

all: $(NAME)

$(NAME):
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR), $(MSRCS)) $(INCLUDE) $(LIBRARY) -framework OpenGL -framework AppKit -o $@

bonus:
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(addprefix $(SRC_DIR), $(BSRCS)) $(INCLUDE) $(LIBRARY) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

mdebug:
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) -g -fsanitize=address $(CFLAGS) $(addprefix $(SRC_DIR), $(MSRCS)) $(INCLUDE) $(LIBRARY) -framework OpenGL -framework AppKit -o $(NAME)

bdebug:
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) -g -fsanitize=address $(CFLAGS) $(addprefix $(SRC_DIR), $(BSRCS)) $(INCLUDE) $(LIBRARY) -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: clean fclean re all
