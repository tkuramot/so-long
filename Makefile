NAME = so_long
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(LIBFT_PATH)/include -I $(MLX_PATH) -I src
LIBRARY = -L $(MLX_PATH) -l $(MLX) -L $(LIBFT_PATH) -l $(LIBFT) \
	-L/usr/X11R6/lib -lX11 -lXext
SRCS = main.c
LIBFT = ft
LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx
MLX = mlx

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	cp $(MLX_PATH)/libmlx.dylib .
	$(CC) $(CFLAGS) $(addprefix src/, $(SRCS)) $(INCLUDE) $(LIBRARY) -framework OpenGL -framework AppKit -o $@

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJS) $(B_SRCS:.c=.o) libmlx.dylib

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: bonus clean fclean re all
