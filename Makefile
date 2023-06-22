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
INCLUDE = -I $(LIBFT_PATH)/include -I $(MLX_PATH)
LIBRARY = -L $(MLX_PATH) -l $(MLX) -L $(LIBFT_PATH) -l $(LIBFT) \
	-L/usr/X11R6/lib -lX11 -lXext
SRCS = main.c parse_map.c validate_map.c validate_map_helper.c \
	load_texture.c draw_screen.c handle_event.c utils.c exit.c
OBJS = $(SRCS:.c=.o)
LIBFT = ft
LIBFT_PATH = ./lib/libft
MLX_PATH = ./lib/minilibx-linux
MLX = mlx_Darwin

all: $(NAME)

$(NAME): $(addprefix src/, $(OBJS))
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(addprefix src/, $(OBJS)) $(LIBRARY) -framework OpenGL -framework AppKit -o $(NAME)

.c.o: $(addprefix src/, $(OBJS))
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	# /opt/homebrew/bin/gcc-13 -g -fsanitize=leak $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJS) $(addprefix src/, $(OBJS))

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

debug:
	leaks -atExit -- ./so_long maps/default_map.ber > log

.PHONY: clean fclean re all
