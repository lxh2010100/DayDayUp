#include <stdio.h>

int factorial(int num)
{
    int result = 0;
    if (num == 1)
        result = 1;
    else
        result = num * factorial(num - 1);
    return result;
}

int main(int argc, char *argv[])
{
    for (size_t i = 1; i <= 10; i++)
    {
        printf("!%ld = %d\n", i, factorial(i));
    }

    int sum = 0;
    for (size_t i = 1; i <= 10; i++)
    {
        sum = sum + factorial(i);
    }
    printf("sum = %d\n", sum);
    return 0;
}