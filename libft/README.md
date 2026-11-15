*This project has been created as part of the 42 curriculum by oezzahi.*
# Libft

## Description
Libft is a custom C library that reimplements standard C library functions and provides additional utility functions, including linked-list manipulation.

## Library Contents

### Character Functions
- `ft_isalpha`: Checks whether a character is an alphabetic letter.
- `ft_isdigit`: Checks whether a character is a digit (0–9).
- `ft_isalnum`: Checks whether a character is alphanumeric (a letter or digit).
- `ft_isascii`: Checks whether a value belongs to the ASCII character set (0–127).
- `ft_isprint`: Checks whether a character is printable (ASCII 32–126).
- `ft_toupper`: Converts a lowercase letter to uppercase.
- `ft_tolower`: Converts an uppercase letter to lowercase.

### String Functions
- `ft_strlen`: Calculates the length of a string, excluding the null terminator.
- `ft_strlcpy`: Copies a string into a destination buffer with size limitation.
- `ft_strlcat`: Appends a string to a destination buffer with size limitation.
- `ft_strchr`: Finds the first occurrence of a character in a string.
- `ft_strrchr`: Finds the last occurrence of a character in a string.
- `ft_strncmp`: Compares two strings up to a specified number of characters.
- `ft_strnstr`: Searches for a substring within a string, limited by a specified length.
- `ft_strdup`: Allocates memory and creates a duplicate of a string.
- `ft_substr`: Extracts a substring starting at a specified position.
- `ft_strjoin`: Allocates memory and concatenates two strings.
- `ft_strtrim`: Removes specified characters from the beginning and end of a string.
- `ft_split`: Splits a string into an array of strings using a delimiter.
- `ft_strmapi`: Creates a new string by applying a function to each character.
- `ft_striteri`: Applies a function to each character of a string, passing its index.

### Memory Functions
- `ft_memset`: Fills a memory block with a specified byte value.
- `ft_bzero`: Sets a specified number of bytes to zero.
- `ft_memcpy`: Copies a specified number of bytes between memory blocks.
- `ft_memmove`: Copies bytes between memory blocks while handling overlap.
- `ft_memchr`: Searches for a byte value within a memory block.
- `ft_memcmp`: Compares two memory blocks byte by byte.
- `ft_calloc`: Allocates memory for multiple elements and initializes it to zero.

### Conversion Functions
- `ft_atoi`: Converts the initial numeric portion of a string to an integer.
- `ft_itoa`: Converts an integer into a newly allocated string.

### Output Functions
- `ft_putchar_fd`: Writes a character to a specified file descriptor.
- `ft_putstr_fd`: Writes a string to a specified file descriptor.
- `ft_putendl_fd`: Writes a string followed by a newline to a specified file descriptor.
- `ft_putnbr_fd`: Writes an integer to a specified file descriptor.

### Linked-List Functions
- `ft_lstnew`: Creates a new linked-list node.
- `ft_lstadd_front`: Adds a node to the beginning of a linked list.
- `ft_lstsize`: Counts the number of nodes in a linked list.
- `ft_lstlast`: Returns the last node of a linked list.
- `ft_lstadd_back`: Adds a node to the end of a linked list.
- `ft_lstdelone`: Deletes a single node and frees its content using a supplied function.
- `ft_lstclear`: Deletes and frees all nodes in a list using a supplied function.
- `ft_lstiter`: Applies a function to the content of each node.
- `ft_lstmap`: Creates a new list by applying a function to each node's content.
## Instructions
Compile the library using:
```bash
make
```
This generates **libft.a** file. Include libft.h in your source files:
```c
#include "libft.h"
```
Then link the library during compilation:
```bash
cc source.c libft.a -o program
```

### requirements
- a C compiler, such as `gcc`
- `make`


## Resources
- [42 project subject](https://cdn.intra.42.fr/pdf/pdf/226739/en.subject.pdf)
- [Man pages](https://man7.org/linux/man-pages/)
- [C tutorial](https://phy.ntnu.edu.tw/~cchen/pdf/ctutor.pdf)

**AI Usage:** AI was used to explain concepts. All implementations and testing were performed as part of the learning process.