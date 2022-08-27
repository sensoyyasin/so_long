NAME = mlx.a
SRC = $(wildcard *.c)
CC = gcc -g
CFLAGS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft.a -lmlx -framework OpenGL -framework AppKit -L ./minilibx
OBJ = $(SRC:.c = .o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) *.c $(CFLAGS) -o so_long

clean:
	rm -rf so_long

fclean: clean

re: clean fclean all

