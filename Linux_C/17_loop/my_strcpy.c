#include <stdio.h>
char *my_strcpy(char *dest, const char *src)
{
    char *tmp = dest;
    while (*dest++ = *src++)
    {
        /* code */
    }
    return tmp;
}

int main(int argc, char **argv)
{
    char src[10] = "hello";
    char dest[20] = "xxxxxxxxxxxxxx";
    char *res;
    res = my_strcpy(dest, src);
    printf("%s\n", res);
    printf("%s\n", dest);
    return 0;
}