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
    DIR *dir = NULL;
    if ((dir = opendir(argv[1])) == NULL)
    {
        perror("mkdir failed\n");
        return -2;
    }
    closedir(dir);
    return 0;
}