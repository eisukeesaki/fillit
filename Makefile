CC=gcc
CFLAGS=-Wall -Wextra -Werror
CSRC=fillit.c \
	 fill_board.c \
	 place_tetromino.c \
	 read_tetromino.c \
	 validate_tetromino.c
OBJS=fillit.o \
	 fill_board.o \
	 place_tetromino.o \
	 read_tetromino.o \
	 validate_tetromino.o
RM=rm -rf
NAME=fillit

$(NAME):
	$(CC) $(CFLAGS) -c $(CSRC) -I libft
	$(CC) $(CFLAGS) $(OBJS) -I libft -L libft -lft -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
