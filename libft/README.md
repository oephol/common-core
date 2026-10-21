*This project has been created as part
of the 42 curriculum by \<oezzahi\>*
# Libft

## Description
Libft is a custom C library that reimplements standard C library functions and provides additional utility functions, including linked-list manipulation.

## Library Contents

- **Character Functions:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- **String Functions:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`
- **Memory Functions:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **Conversion Functions:** `ft_atoi`, `ft_itoa`
- **Output Functions:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Linked-List Functions:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`
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
- a C compiler, such as `cc`
- `make`


## Resources
- [42 project subject](https://cdn.intra.42.fr/pdf/pdf/226739/en.subject.pdf)
- [Man pages](https://man7.org/linux/man-pages/)
- [C tutorial](https://phy.ntnu.edu.tw/~cchen/pdf/ctutor.pdf)

**AI Usage:** AI was used to explain concepts. All implementations and testing were performed as part of the learning process.