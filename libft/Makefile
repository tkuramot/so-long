NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I libft.h -I get_next_line.h -I ft_printf.h
M_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
				ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
				ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				get_next_line.c get_next_line_utils.c \
				ft_printf.c ft_printf_utils.c ft_printf_ptr.c \
				ft_printf_char.c ft_printf_str.c \
				ft_printf_int.c ft_printf_uint.c ft_printf_lower_hex.c \
				ft_printf_upper_hex.c ft_printf_percent.c \
				ft_putchar_r.c ft_putstr_r.c ft_putnstr_r.c
B_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS = $(M_SRCS:.c=.o)
ifdef WITH_BONUS
	OBJS += $(B_SRCS:.c=.o)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus:
	make WITH_BONUS=1

.c.o: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS) $(B_SRCS:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus clean fclean re all
