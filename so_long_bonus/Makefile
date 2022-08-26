NAME = main.a
SRC = $(wildcard *.c)
CC = gcc -g
CFLAGS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ./libft/libft.a -lmlx -framework OpenGL -framework AppKit -L ./minilibx -g

all : $(NAME)

$(NAME):
	$(CC) *.c $(CFLAGS)

clean:
	rm -rf so_long

fclean: clean

re: clean fclean all

