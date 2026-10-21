#include "../libft1/libft.h"
#include <stdio.h>
//////////////////////////////////////////////
void test_strrchr(void)
{
       char *s;
       int c = 'l';

       s = "lorem ipsum door sit amet";
       printf("[%s] [%s]\n\n", ft_strrchr(s, c), strrchr(s, c));
       c = 'm';
       printf("[%s] [%s]\n\n", ft_strrchr(s, c), strrchr(s, c));
       c = 'z';
       printf("[%s] [%s]\n\n", ft_strrchr(s, c), strrchr(s, c));
       c = 0;
       printf("[%s] [%s]\n\n", ft_strrchr(s, c), strrchr(s, c));
       s = "";
       printf("[%s] [%s]\n\n", ft_strrchr(s, c), strrchr(s, c));
       printf("[%lu] ", (unsigned long)ft_strrchr(s, c));
       printf("[%lu]\n", (unsigned long)strrchr(s, c));
       c = 'l' + 256;
       printf(" 6 - [%lu] [%lu]\n\n", (unsigned long)ft_strrchr(s, c), (unsigned long)strrchr(s, c));
       c = 'l';
       char *d = NULL;
       printf("[dd%s]\n", ft_strrchr(d, c));
       printf("[%s]\n", strrchr(d, c));
}
////////////////////////////////////////////////////////////////
void test_strchr(void)
{
       char *s;
       int c = 'l';

       s = "lorem ipsum dolor sit amet";
       printf("1   [%s] [%s]\n\n", ft_strchr(s, c), strchr(s, c));
       c = 'm';
       printf("2   [%s] [%s]\n\n", ft_strchr(s, c), strchr(s, c));
       c = 'z';
       printf("3   [%s] [%s]\n\n", ft_strchr(s, c), strchr(s, c));
       c = '\0';
       printf("4   [%s] [%s]\n\n", ft_strchr(s, c), strchr(s, c));
       s = "";
       printf("5   [%s] [%s]\n\n", ft_strchr(s, c), strchr(s, c));
       printf("6   [%lu] ", (unsigned long)ft_strchr(s, c));
       printf(" [%lu]\n\n", (unsigned long)strchr(s, c));
       c = 24355456;
       printf("7   [%s] [%s]\n\n", ft_strchr(s, c), strchr(s, c));

       s = "tripouille";
       printf("=========================================================\n");
	/* 1 */ printf("1 - [%lu]   [%lu]\n", (unsigned long)ft_strchr(s, 't'), (unsigned long)strchr(s, 't'));
	/* 2 */ printf("2 - [%lu]   [%lu]\n", (unsigned long)ft_strchr(s, 'l'), (unsigned long)strchr(s, 'l'));
	/* 3 */ printf("3 - [%lu]   [%lu]\n", (unsigned long)ft_strchr(s, 'z'), (unsigned long)strchr(s, 'z'));
	/* 4 */ printf("4 - [%lu]   [%lu]\n", (unsigned long)ft_strchr(s, 0), (unsigned long)strchr(s, 0));
	/* 5 */ printf("5 - [%lu]   [%lu]\n", (unsigned long)ft_strchr(s, 't' + 256), (unsigned long)strchr(s, 't' + 256));

       //c = 'l';
       //s = NULL;
}
///////////////////////////////////////////////////////////////////
void test_strlcpy(void)
{
       char *dest = malloc(15);

       memset(dest, 0, 15);
       memset(dest, 'r', 6);
       printf("1[%d]\t[%s]\n", (int)ft_strlcpy(dest, "lorem", 15), dest);
       printf("2[%d]\t[%s]\n", (int)ft_strlcpy(dest, "", 15), dest);
       printf("3[%d]\t[%s]\n", (int)ft_strlcpy(dest, "lorem ipsum", 3), dest);
       printf("4[%d]\t[%s]\n",
              (int)ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15), dest);
       printf("5[%d]\t[%s]\n",
              (int)ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0), dest);
       printf("6 - [%zu]\n", ft_strlcat("haha", "hello", 5));
}
//////////////////////////////////////////////
char *strnstr(const char *haystack, const char *needle, size_t len)
{
       size_t nlen = strlen(needle);
       if (nlen == 0)
              return ((char *)haystack);
       while (*haystack && len >= nlen)
       {
              if (*haystack == *needle && !strncmp(haystack, needle, nlen))
                     return ((char *)haystack);
              haystack++;
              len--;
       }
       return (NULL);
}
void test_strnstr(void)
{
       const char *ft_result;
       const char *std_result;

       // Test case 1
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15);
       std_result = strnstr("lorem ipsum dolor sit amet", "lorem", 15);
       printf("Test 1: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 2
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15);
       std_result = strnstr("lorem ipsum dolor sit amet", "ipsum", 15);
       printf("Test 2: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 3
       ft_result = ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35);
       std_result = strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35);
       printf("Test 3: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 4
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "", 10);
       std_result = strnstr("lorem ipsum dolor sit amet", "", 10);
       printf("Test 4: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 5
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30);
       std_result = strnstr("lorem ipsum dolor sit amet", "ipsumm", 30);
       printf("Test 5: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 6
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "dol", 30);
       std_result = strnstr("lorem ipsum dolor sit amet", "dol", 30);
       printf("Test 6: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 7
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30);
       std_result = strnstr("lorem ipsum dolor sit amet", "consectetur", 30);
       printf("Test 7: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 8
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10);
       std_result = strnstr("lorem ipsum dolor sit amet", "sit", 10);
       printf("Test 8: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 9
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
       std_result = strnstr("lorem ipsum dolor sit amet", "dolor", 15);
       printf("Test 9: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");

       // Test case 10
       ft_result = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0);
       std_result = strnstr("lorem ipsum dolor sit amet", "dolor", 0);
       printf("Test 10: ft_strnstr = %s | strnstr = %s\n",
              ft_result ? ft_result : "NULL",
              std_result ? std_result : "NULL");
}
//////////////////////////////////////////////////////////////
void test_strncmp(void)
{
       printf("1 - [%d] [%d]\n", ft_strncmp("salut", "salut", 5), strncmp("salut", "salut", 5));
       printf("2 - [%d] [%d]\n", ft_strncmp("test", "testss", 7), strncmp("test", "testss", 7));
       printf("3 - [%d] [%d]\n", ft_strncmp("testss", "test", 7), strncmp("testss", "test", 7));
       printf("4 - [%d] [%d]\n", ft_strncmp("test", "tEst", 4), strncmp("test", "tEst", 4));
       printf("5 - [%d] [%d]\n", ft_strncmp("", "test", 4), strncmp("", "test", 4));
       printf("6 - [%d] [%d]\n", ft_strncmp("test", "", 4), strncmp("test", "", 4));
       printf("7 - [%d] [%d]\n", ft_strncmp("abcdefghij", "abcdefgxyz", 3), strncmp("abcdefghij", "abcdefgxyz", 3));
       printf("8 - [%d] [%d]\n", ft_strncmp("abcdefgh", "abcdwxyz", 4), strncmp("abcdefgh", "abcdwxyz", 4));
       printf("9 - [%d] [%d]\n", ft_strncmp("zyxbcdefgh", "abcdwxyz", 0), strncmp("zyxbcdefgh", "abcdwxyz", 0));
       printf("10 - [%d] [%d]\n", ft_strncmp("abcdefgh", "", 0), strncmp("abcdefgh", "", 0));
       printf("11 - [%d] [%d]\n", ft_strncmp("test\200", "test\0", 6), strncmp("test\200", "test\0", 6));
       // printf("2 - [%d] [%d]", ft_strncmp(), strncmp());
}
/////////////////////////////////////////////////////////////////
void test_atoi(void)
{
       printf("1 - [%d],  [%d]\n", ft_atoi("0"), atoi("0"));
       printf("2 - [%d],  [%d]\n", ft_atoi("546:5"), atoi("546:5"));
       printf("3 - [%d],  [%d]\n", ft_atoi("-4886"), atoi("-4886"));
       printf("4 - [%d],  [%d]\n", ft_atoi("+548"), atoi("+548"));
       printf("5 - [%d],  [%d]\n", ft_atoi("054854"), atoi("054854"));
       printf("6 - [%d],  [%d]\n", ft_atoi("000074"), atoi("000074"));
       printf("7 - [%d],  [%d]\n", ft_atoi("+-54"), atoi("+-54"));
       printf("8 - [%d],  [%d]\n", ft_atoi("-+48"), atoi("-+48"));
       printf("9 - [%d],  [%d]\n", ft_atoi("--47"), atoi("--47"));

       printf("10 - [%d],  [%d]\n", ft_atoi("++47"), atoi("++47"));
       printf("11 - [%d],  [%d]\n", ft_atoi("+47+5"), atoi("+47+5"));
       printf("12 - [%d],  [%d]\n", ft_atoi("-47-5"), atoi("-47-5"));
       printf("13 - [%d],  [%d]\n", ft_atoi("\e475"), atoi("\e475"));
       printf("14 - [%d],  [%d]\n", ft_atoi("\t\n\r\v\f  469 \n"), atoi("\t\n\r\v\f  469 \n"));
       printf("15 - [%d],  [%d]\n", ft_atoi("-2147483648"), atoi("-2147483648"));
       printf("16 - [%d],  [%d]\n", ft_atoi("2147483647"), atoi("2147483647"));
       printf("17 - [%d],  [%d]\n", ft_atoi("\t\n\r\v\fd469 \n"), atoi("\t\n\r\v\fd469 \n"));
       printf("18 - [%d],  [%d]\n", ft_atoi("\n\n\n  -46\b9 \n5d6"), atoi("\n\n\n  -46\b9 \n5d6"));
       printf("19 - [%d],  [%d]\n", ft_atoi(""), atoi(""));
}
//////////////////////////////////////////////////////////////////////////////
void test_memchr(void)
{
       char s[] = {0, 1, 2, 3, 4, 5};
       printf("1 - [%zu]  [%zu]\n", (size_t)ft_memchr(s, 0, 0), (size_t)memchr(s, 0, 0));
       printf("2 - [%zu]  [%zu]\n", (size_t)ft_memchr(s, 0, 1), (size_t)memchr(s, 0, 1));
       printf("3 - [%zu]  [%zu]\n", (size_t)ft_memchr(s, 2, 3), (size_t)memchr(s, 2, 3));
       printf("4 - [%zu]  [%zu]\n", (size_t)ft_memchr(s, 6, 6), (size_t)memchr(s, 6, 6));
       printf("5 - [%zu]  [%zu]\n", (size_t)ft_memchr(s, 2 + 256, 3), (size_t)memchr(s, 2 + 256, 3));
}
////////////////////////////////////////////////////////////////////////////
void test_memcmp(void)
{
       char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	/* 1 */ printf("1 - [%d]  [%d]\n", ft_memcmp(s, sCpy, 4), memcmp(s, sCpy,4));
	/* 2 */ printf("2 - [%d]  [%d]\n", ft_memcmp(s, s2, 0), memcmp(s, s2,0));
	/* 3 */ printf("3 - [%d]  [%d]\n", ft_memcmp(s, s2, 1) , memcmp(s, s2,1));
	/* 4 */ printf("4 - [%d]  [%d]\n", ft_memcmp(s2, s, 1) , memcmp(s2, s,1));
	/* 5 */ printf("5 - [%d]  [%d]\n", ft_memcmp(s2, s3, 4) ,memcmp(s2, s3,4));
}
/////////////////////////////////////////////////////////

void	test_substr(void)
{
	char	*result;

	printf("\n===== ft_substr TESTS =====\n");

	result = ft_substr("Hello World", 0, 5);
	printf("Basic:          %s | Expected: Hello | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "Hello") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello World", 6, 5);
	printf("Middle:         %s | Expected: World | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "World") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello World", 0, 20);
	printf("Length > size:  %s | Expected: Hello World | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "Hello World") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello World", 6, 100);
	printf("Long length:    %s | Expected: World | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "World") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello World", 3, 4);
	printf("Limited length: %s | Expected: lo W | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "lo W") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 2, 0);
	printf("Zero length:    %s | Expected: empty string | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 5, 3);
	printf("Start at end:   %s | Expected: empty string | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 10, 3);
	printf("Start past end: %s | Expected: empty string | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("", 0, 5);
	printf("Empty source:   %s | Expected: empty string | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 1, 1);
	printf("Single char:    %s | Expected: e | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "e") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 0, 1);
	printf("First char:     %s | Expected: H | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "H") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 4, 1);
	printf("Last char:      %s | Expected: o | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "o") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 0, 5);
	printf("Exact length:   %s | Expected: Hello | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "Hello") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 2, 10);
	printf("Truncate end:   %s | Expected: llo | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "llo") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr("Hello", 0, 0);
	printf("Empty result:   %s | Expected: empty string | %s\n",
		result ? result : "NULL",
		result && strcmp(result, "") == 0 ? "PASS" : "FAIL");
	free(result);

	result = ft_substr(NULL, 0, 5);
	printf("NULL source:    %s | Expected: NULL | %s\n",
		result ? result : "NULL",
		result == NULL ? "PASS" : "FAIL");
	free(result);
}

////////////////////////////////////////////////////////////////////
void   test_strtrim(void)
{
       printf("1 - [%s]\n", ft_strtrim("   xxx   xxx  ", "x "));
       printf("2 - [%s]\n", ft_strtrim("   xxxtripouille  ", "x "));
       printf("3 - [%s]\n", ft_strtrim("tripouille   xxx", " x"));
       printf("4 - [%s]\n", ft_strtrim("  xxxtripouille   xxx", " x"));
       printf("5 - [%s]\n", ft_strtrim("", "123"));
       printf("6 - [%s]\n", ft_strtrim("123", ""));
       printf("7 - [%s]\n", ft_strtrim("", ""));
       printf("8 - [%s]\n", ft_strtrim("abcdba", "acb"));
       printf("9 - [%s]\n", ft_strtrim("ababa", "a"));
}
#include <fcntl.h>
#include <limits.h>
void   test_putnbr_fd(void)
{
       int fd = open("file", O_CREAT | O_RDWR, 0654);
       ft_putnbr_fd(-35354654, fd);
       ft_putendl_fd("", fd);
       ft_putnbr_fd(INT_MIN, fd);
       ft_putendl_fd("", fd);
       ft_putnbr_fd(-42, fd);
       ft_putendl_fd("", fd);
       ft_putnbr_fd(INT_MAX, fd);
       ft_putendl_fd("", fd);
       ft_putnbr_fd(-00003454, fd);
       // ft_putstr_fd("second line", fd);
       // ft_putendl_fd("  2", fd);
       // ft_putchar_fd('x', fd);
       // ft_putchar_fd('x', fd);
       // ft_putchar_fd('x', fd);
       close(fd);

}
#include <ctype.h>

int main()
{
       printf("%d   %d\n", ft_isalpha(EOF), isalpha(EOF));
       // test_strlcpy();
       // test_strrchr();
       // test_strnstr();
       // test_strncmp();
       // test_strchr();
       // test_strtrim();
       //test_atoi();
       //test_memchr();
       // test_memcmp();
       // test_substr();
       // test_putnbr_fd();
}