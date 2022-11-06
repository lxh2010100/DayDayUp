#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("please type a filename\n");
        return 1;
    }
    int fd;
    ssize_t ret;
    char buffer[32]={0};
    char *filename = argv[1];
    printf("filename: %s\n", filename);
    fd = open(filename, O_RDWR);
    if (fd < 0)
    {
        printf("open error,fd=%d\n", fd);
        return 2;
    }
    printf("fd=%d\n", fd);
    ret = read(fd, buffer, 32);
    if (ret < 0)
    {
        printf("read file error ret=%ld\n",ret);
        perror("reasons:");
        return 3;
    }
    printf("string: %s\nthe length of string is %ld\n", buffer, ret);
    close(fd);
    return 0;
}