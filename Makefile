CC = cc #-fsanitize=address -g3

CFLAGS = 

BONUS_SRC = bonus_src/check_walls_bonus.c  bonus_src/helper_bonus.c  bonus_src/mlx_helper_bonus.c  bonus_src/parcing_bonus.c\
			bonus_src/flood_fill_bonus.c   bonus_src/main_bonus.c    bonus_src/parcing_2_bonus.c   bonus_src/so_long_bonus.c		

BONUS_OBJ = $(BONUS_SRC:.c=.o)

BONUS_NAME = so_long_bonus

NAME = so_long

MLX = -lmlx -lXext -lX11

SRC = src/check_walls.c src/flod_fill.c src/helper.c src/main.c src/parcing_2.c src/parcing.c src/mlx_helper.c src/mlx_helper_2.c src/norm.c 

LIBFT = libft/ft_strlen.c libft/ft_strncmp.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_itoa.c

GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

PRINTF = ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_puthex.c ft_printf/ft_putnbr.c ft_printf/ft_putptr.c ft_printf/ft_putstr.c ft_printf/ft_put_unsigned.c

OBJ_SO_LONG = $(SRC:.c=.o)

OBJ_PRINTF = $(PRINTF:.c=.o)

OBJ_LIBFT = $(LIBFT:.c=.o)

OBJ_GET = $(GET:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SO_LONG) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF) includes/so_long.h
	$(CC) $(CFLAGS) $(OBJ_SO_LONG) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF) -o $(NAME) $(MLX)

bonus: $(BONUS_OBJ) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF) includes/so_long.h
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF) -o $(BONUS_NAME) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SO_LONG) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ_SO_LONG) $(OBJ_GET) $(OBJ_LIBFT) $(OBJ_PRINTF) $(BONUS_OBJ)
