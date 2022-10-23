#include <stdio.h>
int main(int argc, char *argv[]) 
{
#ifdef WW1
    printf("hello world1\n");
#endif

#ifdef WW2
    printf("hello world2\n");
#endif
    return 0;
}