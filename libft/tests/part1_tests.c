#include "../libft1/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

////////////////////////////////////////////////////////////////
// 1. CHARACTER CHECKS & CONVERSIONS
////////////////////////////////////////////////////////////////
void test_chars(void)
{
       printf("===== CHARACTER TESTS =====\n");
       
       // isalpha
       printf("isalpha(EOF): ft = %d | std = %d\n", ft_isalpha(EOF), isalpha(EOF));
       printf("isalpha('A'): ft = %d | std = %d\n", ft_isalpha('A'), isalpha('A'));
       printf("isalpha('1'): ft = %d | std = %d\n", ft_isalpha('1'), isalpha('1'));

       // isdigit
       printf("isdigit('5'): ft = %d | std = %d\n", ft_isdigit('5'), isdigit('5'));
       printf("isdigit('a'): ft = %d | std = %d\n", ft_isdigit('a'), isdigit('a'));

       // isalnum
       printf("isalnum('z'): ft = %d | std = %d\n", ft_isalnum('z'), isalnum('z'));
       printf("isalnum('?'): ft = %d | std = %d\n", ft_isalnum('?'), isalnum('?'));

       // isascii
       printf("isascii(128): ft = %d | std = %d\n", ft_isascii(128), isascii(128));
       printf("isascii(65):  ft = %d | std = %d\n", ft_isascii(65), isascii(65));

       // isprint
       printf("isprint('\\n'): ft = %d | std = %d\n", ft_isprint('\n'), isprint('\n'));
       printf("isprint('A'):  ft = %d | std = %d\n", ft_isprint('A'), isprint('A'));

       // toupper / tolower
       printf("toupper('a'): ft = %c | std = %c\n", ft_toupper('a'), toupper('a'));
       printf("tolower('Z'): ft = %c | std = %c\n", ft_tolower('Z'), tolower('Z'));
       printf("\n");
}

////////////////////////////////////////////////////////////////
// 2. MEMORY FUNCTIONS
////////////////////////////////////////////////////////////////
void test_memory(void)
{
       printf("===== MEMORY TESTS =====\n");

       // memset
       char buf1[10] = {0};
       char buf2[10] = {0};
       ft_memset(buf1, 'A', 5);
       memset(buf2, 'A', 5);
       printf("memset:    ft = [%s] | std = [%s]\n", buf1, buf2);

       // bzero
       char b1[5] = "test";
       char b2[5] = "test";
       ft_bzero(b1, 2);
       bzero(b2, 2);
       printf("bzero:     ft[0]=%d, ft[1]=%d\n", b1[0], b1[1]);

       // memcpy
       char src[] = "Hello Tripouille";
       char m1[20] = {0};
       char m2[20] = {0};
       ft_memcpy(m1, src, 12);
       memcpy(m2, src, 12);
       printf("memcpy:    ft = [%s] | std = [%s]\n", m1, m2);

       // memmove (overlapping test)
       char overlap1[] = "abcdefgh";
       char overlap2[] = "abcdefgh";
       ft_memmove(overlap1 + 2, overlap1, 4);
       memmove(overlap2 + 2, overlap2, 4);
       printf("memmove:   ft = [%s] | std = [%s]\n", overlap1, overlap2);

       // memchr
       char mem[] = {0, 1, 2, 3, 4, 5};
       printf("memchr:    ft = [%zu] | std = [%zu]\n", 
              (size_t)ft_memchr(mem, 2, 4), (size_t)memchr(mem, 2, 4));

       // memcmp
       char sA[] = {-128, 0, 127};
       char sB[] = {-128, 0, 42};
       printf("memcmp:    ft = [%d] | std = [%d]\n", 
              ft_memcmp(sA, sB, 3), memcmp(sA, sB, 3));
       printf("\n");
}

////////////////////////////////////////////////////////////////
// 3. BASIC STRINGS & CONVERSIONS
////////////////////////////////////////////////////////////////
void test_strings_basic(void)
{
       printf("===== BASIC STRINGS & CONV TESTS =====\n");

       // strlen
       char *s = "Tripouille";
       printf("strlen:    ft = [%zu] | std = [%zu]\n", ft_strlen(s), strlen(s));

       // strchr
       printf("strchr:    ft = [%s] | std = [%s]\n", ft_strchr(s, 'p'), strchr(s, 'p'));
       printf("strchr(0): ft = [%s] | std = [%s]\n", ft_strchr(s, 0), strchr(s, 0));

       // strrchr
       printf("strrchr:   ft = [%s] | std = [%s]\n", ft_strrchr(s, 'l'), strrchr(s, 'l'));

       // strncmp
       printf("strncmp:   ft = [%d] | std = [%d]\n", 
              ft_strncmp("test", "testss", 7), strncmp("test", "testss", 7));

       // atoi edge cases
       printf("atoi(\"   -469 \\n\"): ft = [%d] | std = [%d]\n", 
              ft_atoi("   -469 \n"), atoi("   -469 \n"));
       printf("atoi(INT_MIN):      ft = [%d] | std = [%d]\n", 
              ft_atoi("-2147483648"), atoi("-2147483648"));

       // strdup
       char *dup = ft_strdup("Hello Libft");
       printf("strdup:    ft = [%s]\n", dup ? dup : "NULL");
       free(dup);
       printf("\n");
}

int main(void)
{
       test_chars();
       test_memory();
       test_strings_basic();
       return (0);
}