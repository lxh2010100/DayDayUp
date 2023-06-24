#include <stdio.h>
enum days
{
    mon,
    tues,
    thus
};
int main(int argc, char **argv)
{
    enum days day = 999;
    printf("day = %d\n", day);
}