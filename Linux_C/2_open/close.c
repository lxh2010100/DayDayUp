#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("you must provide one file name\n");
        return 1;
    }
    int fd;
    char *filename=argv[1];
    fd = open(filename, O_CREAT|O_WRONLY, 0766);
    if (fd < 0) {
        printf("open error,fd=%d\n",fd);
        return 2;
    }
    else
        printf("open file success;fd=%d\n",fd);

    printf("now we close the file first time\n");
    if(close(fd)==0)
        printf("we close success\n");
    else
        printf("we close error\n");


    printf("now we close the file second time\n");
    if(close(fd)==0)
        printf("we close success\n");
    else
        printf("we close error\n");


    return 0;
}