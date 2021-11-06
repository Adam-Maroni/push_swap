CC = clang
FLAGS = -Wall -Wextra -Werror
LIBFT_ARCHIVE = libft/libft.a
DEBUG_FLAGS = -fsanitize=address -g
OUT = push_swap
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
MIN = 0
MAX = 99
INPUT = 565 12 48 32 87 95 6


libft_rule:
	make -C libft/ all

push_swap_rule:
	$(CC) $(FLAGS) -g $(SRC) main.c $(LIBFT_ARCHIVE) -o $(OUT)

all: libft_rule push_swap_rule

clean:
	rm -f $(OBJ)
	make -C libft/ clean
	rm -f *.o

fclean: clean
	rm -rf $(OUT)
	make -C libft/ fclean

re: fclean all

gdb: all
	gdb -x ../tests/gdb_script/1.gdb --args ./$(OUT) $(INPUT)

mem_check:
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(SRC) main.c $(LIBFT_ARCHIVE) -o $(OUT)

test_rule: all
	@ARG=`ruby -e "puts ($(MIN)..$(MAX)).to_a.shuffle.join(' ')"` ; echo $$ARG ;  ./$(OUT) $$ARG | wc -l
