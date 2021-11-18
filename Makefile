CC = clang
CFLAGS = -Wall -Wextra -Werror
LIBFT_ARCHIVE = libft/libft.a
DEBUG_FLAGS = -fsanitize=address -g
NAME = push_swap
SRC = src/checking.c\
src/dll.c\
src/found.c\
src/input_checking.c\
src/instructions.c\
src/instructions_list.c\
src/median.c\
src/new.c\
src/optimize.c\
src/push.c\
src/resolve.c\
src/rotate.c\
src/rotation_tools.c\
src/swap.c\
src/main.c

OBJ = $(SRC:.c=.o)
MIN = 0
MAX = 99
INPUT = 565 12 48 32 87 95 6

libft_rule:
	make -C libft/ all

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_ARCHIVE)

all: libft_rule $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

gdb: all
	gdb -x ../tests/gdb_script/1.gdb --args ./$(NAME) $(INPUT)

mem_check:
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC) main.c $(LIBFT_ARCHIVE) -o $(NAME)

test_rule: all
	@ARG=`ruby -e "puts ($(MIN)..$(MAX)).to_a.shuffle.join(' ')"` ; echo $$ARG ;  ./$(NAME) $$ARG | wc -l




