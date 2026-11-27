NAME = push_swap
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror
SRC =	src/bubble_sort.c \
		src/linked_list.c \
		src/push_swap_ops1.c \
		src/push_swap_utils1.c \
		src/insertion_sort.c \
		src/push_swap_ops2.c \
		src/recording_ops.c \
		src/push_swap_utils2.c \
		src/read_input.c \
		push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c push_swap.h structs.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re