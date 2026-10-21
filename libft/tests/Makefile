CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
SRC = ../libft1/../libft1/ft_atoi.c ../libft1/ft_bzero.c ../libft1/ft_calloc.c ../libft1/ft_isalnum.c \
	../libft1/ft_isalpha.c ../libft1/ft_isascii.c ../libft1/ft_isdigit.c ../libft1/ft_isprint.c \
	../libft1/ft_itoa.c ../libft1/ft_lstadd_back.c ../libft1/ft_lstadd_front.c ../libft1/ft_lstdelone.c \
      ../libft1/ft_lstiter.c ../libft1/ft_lstlast.c ../libft1/ft_lstmap.c ../libft1/ft_lstnew.c \
      ../libft1/ft_lstsize.c ../libft1/ft_lstclear.c ../libft1/ft_memchr.c ../libft1/ft_memcmp.c \
      ../libft1/ft_memcpy.c ../libft1/ft_memmove.c ../libft1/ft_memset.c ../libft1/ft_putchar_fd.c \
      ../libft1/ft_putendl_fd.c ../libft1/ft_putnbr_fd.c ../libft1/ft_putstr_fd.c ../libft1/ft_split.c \
      ../libft1/ft_strchr.c ../libft1/ft_strdup.c ../libft1/ft_striteri.c ../libft1/ft_strjoin.c \
      ../libft1/ft_strlcat.c ../libft1/ft_strlcpy.c ../libft1/ft_strlen.c ../libft1/ft_strmapi.c \
      ../libft1/ft_strncmp.c ../libft1/ft_strnstr.c ../libft1/ft_strrchr.c ../libft1/ft_strtrim.c \
      ../libft1/ft_substr.c ../libft1/ft_tolower.c ../libft1/ft_toupper.c

OBJ = $(SRC:.c=.o)

all: part1_tests part2_tests part3_tests

1: $(OBJ) ../libft1/libft.h
	$(CC) $(CFLAGS) $(OBJ) part1_tests.c -o part1 

2: $(OBJ) ../libft1/libft.h
	$(CC) $(CFLAGS) $(OBJ) part2_tests.c -o part2

3: $(OBJ) ../libft1/libft.h
	$(CC) $(CFLAGS) $(OBJ) part3_tests.c -o part3

%.o: %.c ../libft1/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f part1 part2 part3

re: fclean all

.PHONY: all clean fclean re
