#include <stdio.h>
int main (int argc, char **argv)
{
    int i=10;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    for (i=0; i<=12; i++)
    {
        arr[i]=i;
        printf("OK--.i=%d\n",i);
    }
    return 0;
}