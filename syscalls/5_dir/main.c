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
    DIR *dp = NULL;
    char pathname[32];
    struct dirent *dir;
    int fd_src, fd_dest;
    ssize_t size_src, size_dest;
    char buffer[100];
    printf("please input pathname:\n");
    scanf("%s", pathname);
    printf("------->%s\n", pathname);

    dp = opendir(pathname);
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
    printf("please input the filename you copy:\n");
    scanf("%s", pathname);
    fd_src = open(pathname, O_RDONLY);
    printf("------->%s\n", pathname);

    printf("please input the new filename:\n");
    scanf("%s", pathname);
    fd_dest = open(pathname, O_CREAT | O_WRONLY, 0666);
    printf("------->%s\n", pathname);

    while ((size_src = read(fd_src, buffer, sizeof(buffer))) != 0)
    {
        size_dest = write(fd_dest, buffer, size_src);
    }
    close(fd_dest);
    close(fd_src);
    return 0;
}