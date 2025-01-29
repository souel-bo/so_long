CC = cc #-fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRC = src/check_walls.c src/flod_fill.c src/helper.c src/main.c src/parcing_2.c src/parcing.c src/mlx_helper.c src/mlx_helper_2.c

LIBFT = libft/ft_strlen.c libft/ft_strncmp.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c 

GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

PRINTF = ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex.c ft_printf/ft_putnbr.c ft_printf/ft_putptr.c ft_printf/ft_putstr.c ft_printf/ft_put_unsigned.c

OBJ_SO_LONG = $(SRC:.c=.o)

OBJ_PRINTF = $(PRINTF:.c=.o)

OBJ_LIBFT = $(LIBFT:.c=.o)

OBJ_GET = $(GET:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SO_LONG) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_SO_LONG) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF) -o $(NAME) $(MLX)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_SO_LONG) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
