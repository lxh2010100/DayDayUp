#include <stdio.h>
int main(int argc, char **argv)
{
    char a = 127;
    char b = a + 1;
    printf("a=%d\nb=%d\n", a, b);
}
/*

127: 0111 1111
1  : 0000 0001
二者相加的补码
   : 1000 0000
已知补码求源码
先 -1
0111 1111
按位取反
1000 0000
128
加上负号
-128
*/