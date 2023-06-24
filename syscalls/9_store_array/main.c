#include <stdio.h>
#include "fun.h"
struct arry_info arry;

int main(int argc, char **argv)
{
    init_array(&arry, 10);
    for (int index = 0; index < arry.max_length - 1; index++)
    {
        append_array(&arry, index + 4);
    }
    show_array(&arry);
    insert_array(&arry, 4, 2220);
    show_array(&arry);
    delete_array(&arry, 2);
    show_array(&arry);
    change_array(&arry, 5, 123);
    show_array(&arry);
    find_array(&arry, 123);
    sort_array(&arry);
    show_array(&arry);
    return 0;
}