#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(int argc, char **argv)
{
    char myarr[100];
    char *parr[3];
    printf("please enter your string\n");
    for (size_t i = 0; i < 3; i++)
    {
        scanf("%s", myarr);
        parr[i] = (char *)malloc((strlen(myarr) + 1) * sizeof(char));
        memcpy(parr[i], myarr, strlen(myarr) + 1);
    }
    printf("now ,print result\n");

    for (size_t i = 0; i < 3; i++)
    {
        printf("---->%s\n", parr[i]);
        free(parr[i]);
        parr[i] = NULL;
    }
}