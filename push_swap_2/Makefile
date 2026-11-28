NAME = push_swap
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror

INPUT =	src/input/input_utils.c \
		src/input/parse_input.c

OPERATIONS = src/operations/op_log.c \
			src/operations/op_push.c \
			src/operations/op_rotate.c \
			src/operations/op_swap.c \
			src/operations/op_reverse_rotate.c \
			src/operations/op_log_optimise.c

OUTPUT = src/output/print_bench.c \
		src/output/print_operations.c \
		src/output/print_bench_utils.c

SORTING = src/sorting/simple_sort.c \
		src/sorting/medium_sort.c \
		src/sorting/complex_sort.c \
		src/sorting/sort_utils.c

STACK = src/stack/node_utils.c \
		src/stack/stack_pop.c \
		src/stack/stack_push.c \
		src/stack/stack_rotate.c \
		src/stack/stack_swap.c

UTILS = src/utils/free_all.c \
		src/utils/utils_1.c
		
#remove temp.c

SRC = push_swap.c temp.c $(INPUT) $(OPERATIONS) $(OUTPUT) $(SORTING) $(STACK) $(UTILS)

OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c push_swap.h data_structs.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re