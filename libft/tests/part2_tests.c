#include "../libft1/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////
// 1. STRLCPY & STRLCAT
////////////////////////////////////////////////////////////////
void test_strlcpy_lcat(void)
{
       printf("===== STRLCPY & STRLCAT TESTS =====\n");

       // strlcpy
       char dest1[15];
       memset(dest1, 'r', 15);
       size_t r1 = ft_strlcpy(dest1, "lorem", 15);
       printf("strlcpy (normal): ret = %zu | dest = [%s]\n", r1, dest1);

       size_t r2 = ft_strlcpy(dest1, "ipsum", 3);
       printf("strlcpy (small size): ret = %zu | dest = [%s]\n", r2, dest1);

       // strlcat
       char dest2[20] = "Hello";
       size_t r3 = ft_strlcat(dest2, " World", 20);
       printf("strlcat (normal): ret = %zu | dest = [%s]\n", r3, dest2);

       char dest3[5] = "Hi";
       size_t r4 = ft_strlcat(dest3, " Tripouille", 5);
       printf("strlcat (truncation): ret = %zu | dest = [%s]\n", r4, dest3);
       printf("\n");
}

////////////////////////////////////////////////////////////////
// 2. SUBSTR, STRJOIN, STRTRIM
////////////////////////////////////////////////////////////////
void test_string_manip(void)
{
       printf("===== SUBSTR, STRJOIN, STRTRIM TESTS =====\n");

       // ft_substr
       char *sub = ft_substr("Hello World", 6, 5);
       printf("ft_substr:     [%s]\n", sub ? sub : "NULL");
       free(sub);

       char *sub_out = ft_substr("Hello", 10, 3);
       printf("ft_substr(out):[%s] (expected empty)\n", sub_out ? sub_out : "NULL");
       free(sub_out);

       // ft_join
       char *join = ft_strjoin("Hello ", "Libft!");
       printf("ft_strjoin:    [%s]\n", join ? join : "NULL");
       free(join);

       // ft_trim
       char *trim = ft_strtrim("   xxx   tripouille   xxx  ", "x ");
       printf("ft_strtrim:    [%s]\n", trim ? trim : "NULL");
       free(trim);
       printf("\n");
}

////////////////////////////////////////////////////////////////
// 3. SPLIT
////////////////////////////////////////////////////////////////
void test_split(void)
{
       printf("===== SPLIT TESTS =====\n");
       
       char const *s = "  tripouille  does  not  fail  ";
       char **tab = ft_split(s, ' ');
       
       if (!tab)
       {
              printf("ft_split returned NULL\n");
              return;
       }

       int i = 0;
       while (tab[i])
       {
              printf("tab[%d] = [%s]\n", i, tab[i]);
              free(tab[i]);
              i++;
       }
       free(tab);

       // Edge case: empty string / delimiter only
       char **tab_empty = ft_split("", ',');
       printf("ft_split(\"\", ','): tab[0] = %s\n", tab_empty && tab_empty[0] == NULL ? "NULL (PASS)" : "FAIL");
       free(tab_empty);
       printf("\n");
}

////////////////////////////////////////////////////////////////
// 4. ITOA & MAPPERS
////////////////////////////////////////////////////////////////
char test_map_cb(unsigned int index, char c)
{
       return (c + index);
}

void test_iter_cb(unsigned int index, char *c)
{
       if (*c >= 'a' && *c <= 'z')
              *c = *c - 32 + index; // Custom logic
}

void test_itoa_and_maps(void)
{
       printf("===== ITOA & MAPPERS TESTS =====\n");

       // ft_itoa
       char *n1 = ft_itoa(-2147483648LL < 0 ? -2147483647 - 1 : 0); // handling INT_MIN safe
       char *n2 = ft_itoa(2147483647);
       char *n3 = ft_itoa(0);
       char *n4 = ft_itoa(-42);

       printf("ft_itoa(INT_MIN): [%s]\n", ft_itoa(-2147483647 - 1));
       printf("ft_itoa(INT_MAX): [%s]\n", n2);
       printf("ft_itoa(0):       [%s]\n", n3);
       printf("ft_itoa(-42):     [%s]\n", n4);

       free(n1); free(n2); free(n3); free(n4);

       // ft_strmapi
       char *mapped = ft_strmapi("aaaa", test_map_cb);
       printf("ft_strmapi:       [%s] (expected abcd)\n", mapped ? mapped : "NULL");
       free(mapped);

       // ft_striteri
       char str_mut[] = "aaaa";
       ft_striteri(str_mut, test_iter_cb);
       printf("ft_striteri:      [%s]\n", str_mut);
       printf("\n");
}

int main(void)
{
       test_strlcpy_lcat();
       test_string_manip();
       test_split();
       test_itoa_and_maps();
       return (0);
}