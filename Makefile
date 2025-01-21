CC = cc #-fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
BONUS_NAME = checker

SRC= ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_strncmp.c get_next_line.c get_next_line_utils.c\
		 helper.c main.c parcing_2.c parcing.c check_walls.c

OBJ = $(SRC:.c=.o)
#BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

#bonus: $(BONUS_NAME)

#$(BONUS_NAME): $(BONUS_OBJ) push_swap.h
#@$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

$(NAME): $(OBJ) so_long.h
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ) #$(BONUS_OBJ)
