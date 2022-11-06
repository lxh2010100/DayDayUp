#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
    int fd;
    int ret;
    if (argc < 2)
    {
        printf("Usage: %s <fifo file name>\n", argv[0]);
        return 1;
    }

    if ((access(argv[1], F_OK)) == -1)
    {
        printf("fifo file is not exist\n");
        if (mkfifo(argv[1], 0666))
        {
            printf("mkfifo failed\n");
            perror("mkfifo failed :");
            return 2;
        }
        printf("mkfifo succeeded\n");

        fd = open(argv[1], O_WRONLY);
        while (1)
        {
            write(fd, "hello world", 11);
            sleep(1);
        }
        close(fd);
    }
    return 0;
}