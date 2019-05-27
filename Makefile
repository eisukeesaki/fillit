CC=gcc
CFLAGS=-Wall -Wextra -Werror -I libft
OBJS=fillit.o \
	 check_parity.o \
	 fill_board.o \
	 place_tetromino.o \
	 read_tetromino.o \
	 validate_tetromino.o
RM=rm -rf
NAME=fillit

vpath libft.a libft

$(NAME): $(OBJS) -lft
	@echo Compiling fillit executable...
	@$(CC) $(CFLAGS) $(OBJS) -I libft -L libft -lft -o $(NAME)

all: $(NAME)

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning fillit executable..."
	@$(RM) $(NAME)

re: fclean all
