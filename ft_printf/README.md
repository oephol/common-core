*This project has been created as part of the 42 curriculum by oezzahi.*

# ft_printf

## Description

The **ft_printf** project consists of recoding the standard C `printf()` function from the C standard library.

The goal is to understand variadic functions in C, format strings, and how arguments are processed and printed.

The resulting library, `libftprintf.a`, provides a custom implementation of `ft_printf()` that supports the mandatory conversions.

## Supported Conversions

| Conversion | Description |
|:---:|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal |
| `%d` | Prints a decimal integer |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%%` | Prints a percent sign |

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This generates `libftprintf.a` at the root of the repository.

Available Makefile rules:

- `make` or `make all` — Compile the library.
- `make clean` — Remove object files.
- `make fclean` — Remove object files and the library.
- `make re` — Recompile the library.

### Usage

Include the header file in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lftprintf -o program
```

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello, %s! Number: %d\n", "world", 42);
	return (0);
}
```

## Algorithm and Data Structures

The implementation processes the format string character by character.

When a regular character is encountered, it is printed directly. When a `%` character is encountered, the following character is interpreted as a conversion specifier. The corresponding function handles the argument retrieved using the variadic argument macros.

The implementation uses `va_list` to manage the variable arguments passed to `ft_printf()`, together with `va_start`, `va_arg`, and `va_end`.

The approach avoids unnecessary data structures. The format string is processed sequentially, and the number of characters printed is tracked to provide the correct return value.

This design keeps the implementation modular, readable, and extensible.

## Resources

### References

- [C Standard Library — printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C Standard Library — stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)

### AI Usage

AI tools were used only to assist with understanding concepts related to variadic functions, reviewing technical information.
