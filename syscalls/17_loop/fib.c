#include <stdio.h>

int fib(int x)
{
    if (x <= 2)
        return 1;
    else
        return fib(x - 1) + fib(x - 2);
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    int ret = fib(n);
    printf("%d\n", ret);
    return 0;
}