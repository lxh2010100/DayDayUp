#include <stdio.h>
#include <bits/stdint-uintn.h>
void memory_dump(void *ptr, int len)
{
    int i;
    printf("%p\n", ptr);
    for (i = 0; i < len; i++)
    {
        if (i % 8 == 0 && i != 0)
            printf(" ");
        if (i % 16 == 0 && i != 0)
            printf("\n");
        printf("%02x ", *((uint8_t *)ptr + i));
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int a = 0x11223344;
    int b = 1;
    char *p = (char *)&b;
    if (*p)
    {
        printf("小端存储\n");
    }
    else
    {
        printf("大端存储\n");
    }

    return 0;
}