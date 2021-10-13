CC = clang
FLAGS = -Wall -Wextra -Werror
LIBFT_ARCHIVE = libft/libft.a
DEBUG_FLAGS = -fsanitize=address -g
OUT = push_swap
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)


libft_rule:
	make -C libft/ all

push_swap_rule:
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(SRC) main.c $(LIBFT_ARCHIVE) -o $(OUT)

all: libft_rule push_swap_rule

clean:
	rm -f $(OBJ)
	make -C libft/ clean
	rm -f *.o

fclean: clean
	rm -rf $(OUT)
	make -C libft/ fclean

re: fclean all
