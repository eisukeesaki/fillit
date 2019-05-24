CC=gcc
CFLAGS=-Wall -Wextra -Werror -I libft
OBJS=fillit.o \
	 fill_board.o \
	 place_tetromino.o \
	 read_tetromino.o \
	 validate_tetromino.o
RM=rm -rf
NAME=fillit

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I libft -L libft -lft -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
