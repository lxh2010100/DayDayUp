#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arr.h"

bool init_array(struct arry_info *parry, int max)
{
    if (!parry)
        return false;
    if ((parry->pbase = (int *)malloc(sizeof(int) * max)) == NULL)
        return false;
    else
        parry->max_length = max;
    return true;
}
bool is_empty(struct arry_info *parry)
{
    if ((parry == NULL) || (parry->pbase == NULL))
    {
        exit(1);
    }
    if (parry->count == 0)
        return true;
    else
        return false;
}

bool is_full(struct arry_info *parry)
{
    if (parry->count == parry->max_length)
        return true;
    else
        return false;
}
bool append_array(struct arry_info *parry, int var)
{
    if (is_full(parry))
        return false;
    else
    {
        parry->pbase[parry->count] = var;
        parry->count++;
    }
    return true;
}
bool show_array(struct arry_info *parry)
{
    printf("the array length is %d\n", parry->count);
    for (int index = 0; index < parry->count; index++)
    {
        printf("%d ", parry->pbase[index]);
    }
    printf("\n");
    return true;
}
// 0 1 2 3 4 5 6 7 8 9
//        insert100
// 0 1 2 3 99 4 5 6 7 8 9
bool insert_array(struct arry_info *parry, int position, int var)
{
    if (is_full(parry))
        return false;
    parry->count++;
    for (size_t i = parry->count; i != position; i--)
    {
        parry->pbase[i - 1] = parry->pbase[i - 2];
    }
    parry->pbase[position - 1] = var;
    return true;
}

bool delete_array(struct arry_info *parry, int position)
{
    printf("delete var %d\n", parry->pbase[position - 1]);
    for (int i = position; i < parry->count; i++)
    {
        parry->pbase[i - 1] = parry->pbase[i];
    }
    parry->count--;
    return true;
}
bool change_array(struct arry_info *parry, int position, int var)
{
    if (position > parry->count)
    {
        return false;
    }
    else
        parry->pbase[position - 1] = var;
    return true;
}
bool find_array(struct arry_info *parry, int var)
{
    for (int i = 0; i < parry->count; i++)
    {
        if (var == parry->pbase[i])
        {
            printf("the index of var %d  = %d\n", var, i);
            break;
        }
    }
}

bool sort_array(struct arry_info *parry)
{
    for (int i = 0; i < parry->count - 1; i++)
    {
        for (int j = i + 1; j < parry->count; j++)
        {
            if (parry->pbase[i] > parry->pbase[j])
            {
                swap_num(&(parry->pbase[i]), &(parry->pbase[j]));
            }
        }
    }
    perror("perror");
    return true;
}

void swap_num(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}