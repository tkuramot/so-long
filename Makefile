NAME = so_long
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(LIBFT) -I $(MLX)
LIBRARY = -L $(MLX) -l $(MLX) -L $(LIBFT) -l $(LIBFT)
SRCS = so_long.c
LIBFT = libft
MLX = mlx

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(SRCS) $(LIBRARY) -o $(NAME)

clean:
	make -C $(LIBFT) clean
	$(RM) $(OBJS) $(B_SRCS:.c=.o)

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus clean fclean re all