#include <stdio.h>

int main(int argc, char *argv[])
{
    int a = 0;
    printf("~a=%d\n", ~a);
    // 00000000 00000000 000000000 0000000000 补码
    // 11111111 11111111 111111111 1111111111 按位取反
    // 11111111 11111111 111111111 1111111110 -1
    // 10000000 00000000 000000000 0000000001 取反
    // -1
    a = -1;
    printf("~a=%d\n", ~a);
    return 0;
}