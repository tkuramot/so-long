NAME = so_long
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(LIBFT_PATH) -I $(MLX_PATH)
LIBRARY = -L $(MLX_PATH) -l $(MLX) -L $(LIBFT_PATH) -l $(LIBFT) \
	-L/usr/X11R6/lib -lX11 -lXext
SRCS = main.c
LIBFT = ft
LIBFT_PATH = libft
MLX_PATH = mlx
MLX = mlx

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	cp $(MLX_PATH)/libmlx.dylib .
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) $(LIBRARY) -framework OpenGL -framework AppKit -o $@

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJS) $(B_SRCS:.c=.o) libmlx.dylib

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

test: re
	./$(NAME)

.PHONY: bonus clean fclean re all