#include <stdio.h>
#include <stdargs.h>
double sum(int num, ...)
{
    // step 1
    va_list valist;
    // step 2
    double ret = 0.0;
    int i = 0;
    va_start(valist, num); // step 3
    for (int i = 0; i < num; i++)
    {
        ret += va_arg(valist, double); // step 4
    }
    va_end(valist); // step 5
    return ret;
}

int main()
{
    printf("Sum of 2, 3 is %f\n", sum(2, 2, 3));
    printf("Sum of 2, 3, 4, 5 is %f\n", sum(4, 2, 3, 4, 5));
}