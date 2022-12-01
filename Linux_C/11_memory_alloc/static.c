#include <stdio.h>

void func1(int **q)
{
    int i = 99;
    *q = &i;
}

int main(void)
{
    int *p;
    func1(&p);
    printf("*p=%d\n", *p);
    return 0;
}