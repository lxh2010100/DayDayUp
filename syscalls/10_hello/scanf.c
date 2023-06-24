#include <stdio.h>
int main(void)
{
    int i = 0, j = 0;
    char ch;
    scanf("%d", &i);
    while ((ch = getchar()) != '\n')
    {
        continue;
    }

    scanf("%d", &j);
    printf("i=%d, j=%d\n", i, j);
    return 0;
}