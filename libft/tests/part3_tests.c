#include "../libft1/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

////////////////////////////////////////////////////////////////
// 1. FILE DESCRIPTOR FUNCTIONS
////////////////////////////////////////////////////////////////
void test_file_descriptors(void)
{
       printf("===== FILE DESCRIPTOR TESTS =====\n");
       
       int fd = open("test_output.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
       if (fd < 0)
       {
              perror("Failed to open test file");
              return;
       }

       ft_putchar_fd('X', fd);
       ft_putendl_fd("", fd);
       
       ft_putstr_fd("Hello, File Descriptors!\n", fd);
       
       ft_putnbr_fd(42, fd);
       ft_putendl_fd("", fd);
       
       ft_putnbr_fd(-35354654, fd);
       ft_putendl_fd("", fd);
       
       ft_putnbr_fd(INT_MIN, fd);
       ft_putendl_fd("", fd);
       
       ft_putnbr_fd(INT_MAX, fd);
       ft_putendl_fd("", fd);
       
       ft_putnbr_fd(0, fd);
       ft_putendl_fd("", fd);

       close(fd);
       printf("FD functions executed. Check 'test_output.txt' for exact results.\n\n");
}

////////////////////////////////////////////////////////////////
// 2. LINKED LIST FUNCTIONS HELPERS
////////////////////////////////////////////////////////////////
void del_content(void *content)
{
       free(content);
}

void iter_content(void *content)
{
       char *str = (char *)content;
       if (str && str[0])
              str[0] = 'X'; // Modify first letter to test iteration
}

void *map_content(void *content)
{
       char *str = (char *)content;
       char *new_str = strdup(str);
       if (new_str && new_str[0])
              new_str[0] = 'M'; // Transform data for map test
       return (new_str);
}

////////////////////////////////////////////////////////////////
// 3. LINKED LIST FUNCTIONS TESTS
////////////////////////////////////////////////////////////////
void test_linked_lists(void)
{
       printf("===== LINKED LIST TESTS =====\n");

       // ft_lstnew
       t_list *elem1 = ft_lstnew(strdup("alpha"));
       t_list *elem2 = ft_lstnew(strdup("beta"));
       t_list *elem3 = ft_lstnew(strdup("gamma"));

       if (!elem1 || !elem2 || !elem3)
       {
              printf("ft_lstnew failed to allocate nodes.\n");
              return;
       }

       // ft_lstadd_front
       ft_lstadd_front(&elem2, elem1); // list: elem1 -> elem2 -> NULL

       // ft_lstadd_back
       ft_lstadd_back(&elem2, elem3);  // list: elem1 -> elem2 -> elem3 -> NULL

       // ft_lstsize
       int size = ft_lstsize(elem1);
       printf("ft_lstsize:    %d (expected 3)\n", size);

       // ft_lstlast
       t_list *last = ft_lstlast(elem1);
       printf("ft_lstlast:    [%s] (expected gamma)\n", last ? (char *)last->content : "NULL");

       // ft_lstiter
       ft_lstiter(elem1, iter_content);
       printf("ft_lstiter:    [%s], [%s], [%s] (expected X...)\n", 
              (char *)elem1->content, 
              (char *)elem1->next->content, 
              (char *)elem1->next->next->content);

       // ft_lstmap
       t_list *mapped = ft_lstmap(elem1, map_content, del_content);
       printf("ft_lstmap head: [%s] (expected M...)\n", mapped ? (char *)mapped->content : "NULL");

       // ft_lstdelone test standalone
       t_list *single = ft_lstnew(strdup("temp"));
       ft_lstdelone(single, del_content);
       printf("ft_lstdelone:  Executed successfully\n");

       // ft_lstclear
       ft_lstclear(&elem1, del_content);
       ft_lstclear(&mapped, del_content);
       printf("ft_lstclear:   Lists successfully cleared and freed.\n\n");
}

int main(void)
{
       test_file_descriptors();
       test_linked_lists();
       return (0);
}