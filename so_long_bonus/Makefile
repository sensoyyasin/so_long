NAME = main.a
SRC = $(wildcard *.c)
CC = gcc -Wall -Wextra -Werror
CFLAGS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -L ./minilibx

all : $(NAME)

$(NAME):
	$(CC) *.c $(CFLAGS) -o so_long_bonus

clean:
	rm -rf so_long

fclean: clean

re: clean fclean all

