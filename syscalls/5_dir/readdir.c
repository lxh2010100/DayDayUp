#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s < dirrectory name>", argv[1]);
        return -1;
    }
    DIR *dp = NULL;
    dp = opendir(argv[1]);
    struct dirent *dir;

    while (1)
    {
        dir = readdir(dp);
        if (dir == NULL)
        {
            perror("readdir");
            break;
        }
        printf("%s\n", dir->d_name);
    }
    return 0;
}