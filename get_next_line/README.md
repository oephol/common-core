*This project has been created as part of the 42 curriculum by oezzahi.*

# get_next_line

## Description

**get_next_line** is a project from the 42 curriculum that aims to develop a function capable of reading a file or input stream line by line. The function returns one line per call, including the newline character (`\n`) when present, and returns `NULL` when there is nothing more to read or when an error occurs.

The main objective of this project is to gain a deeper understanding of file descriptors, the `read()` system call, static variables, memory allocation, and buffer management in C.

This implementation uses a static buffer to temporarily store data read from a file. It extracts one line at a time while preserving unread data for subsequent calls.

The project includes:

- **Mandatory part:** Reads from a single file descriptor.
- **Bonus part:** Supports multiple file descriptors simultaneously by maintaining an independent buffer for each descriptor.

## Algorithm

### Buffered Line Reading

The algorithm is based on a static buffer and a position index. Instead of reading one character at a time, it reads chunks of data using `read()`, with the chunk size determined by `BUFFER_SIZE`.

The buffer is represented by a structure containing:

- `buf`: The memory storing the data read from the file.
- `pos`: The current position within the buffer.
- `n_read`: The number of bytes read by the last `read()` call.

### How It Works

1. **Validation:** The function checks whether the file descriptor is valid, whether `BUFFER_SIZE` is positive, and whether a previous read error has occurred.
2. **Buffer Refill:** When all buffered data has been consumed, `read()` is called to fill the buffer with new data.
3. **Line Construction:** The function searches for a newline character in the available buffer data.
4. **Memory Allocation:** A new string is dynamically allocated to hold the accumulated line and the newly extracted data.
5. **Data Accumulation:** The contents of the previous line fragment and the new buffer segment are copied into the newly allocated string.
6. **Line Completion:** When a newline is encountered, the completed line is returned.
7. **EOF Handling:** If the end of the file is reached, any remaining characters are returned as the final line. If no characters remain, the function returns `NULL`.

### Algorithm Justification

This approach uses buffered reading rather than reading one character at a time. This reduces the number of system calls and improves efficiency, especially when dealing with large files.

The use of a static buffer allows unread data to persist between function calls, avoiding unnecessary reads. Dynamic memory allocation allows the returned line to have a variable length, independent of the buffer size.

For the bonus part, an array of static buffers indexed by file descriptor is used. This allows the function to maintain independent reading states for multiple files, preventing the buffered data of one file from interfering with another.

The algorithm is straightforward and memory-efficient in terms of buffer storage. However, because the line is reallocated and copied as data is accumulated, long lines may result in repeated copying.

## Instructions

### Compilation

The project is written in C and requires a C compiler such as `cc` or `gcc`.

Clone the repository:

```bash
git clone <your-repository-url> get_next_line
cd get_next_line
```
Include the header in your `.c` file.
```c
#include "get_next_line.c"
//or
#include "get_next_line_bonus.c"
```

Compile the mandatory version:

```bash
cc -Wall -Wextra -Werror \
-D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c -I. \
main.c -o gnl
```

Compile the bonus version:

```bash
cc -Wall -Wextra -Werror \
-D BUFFER_SIZE=42 \
get_next_line_bonus.c get_next_line_utils_bonus.c -I. \
main_bonus.c -o gnl_bonus
```

`BUFFER_SIZE` can be changed at compilation time to test different buffer sizes.

### Execution

Run the compiled program:

```bash
./gnl
```

## Resources

### Documentation

- [read() — Linux Manual Page](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc() — Linux Manual Page](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [free() — Linux Manual Page](https://man7.org/linux/man-pages/man3/free.3.html)
- [Static Variables in C](https://en.cppreference.com/w/c/language/storage_duration.html)
- [File Descriptors — Linux Manual Pages](https://man7.org/linux/man-pages/man2/open.2.html)

### AI Usage

AI tools were used as learning resource during the development of this project.
The implementation, testing, and final integration were carried out by the project author.

