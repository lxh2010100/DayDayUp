#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char **argv)
{
    int fd;
    char buffer[32];
    if (argc < 2)
    {
        printf("usage: %s < fifo file name >\n", argv[0]);
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    while (1)
    {
        read(fd, buffer, 32);
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}