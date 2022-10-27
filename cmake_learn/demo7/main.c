#include <stdio.h>
#include "sub.h"
#include "add.h"
int main(int argc, char **argv)
{
    int x=100,y=90;
    printf("x+y=%d,x-y=%d",add(x,y),sub(x,y));
    return 0;

}