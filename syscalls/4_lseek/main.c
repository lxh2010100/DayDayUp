#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int read_file(int fd, char *buff, int size)
{
    int n;
    while ((n = read(fd, buff, size)))
    {
        if (n < 0)
        {
            perror("read error");
            exit(1);
        }
        write(STDOUT_FILENO, buff, size);
    }
    printf("\n");
    return 0;
}

void print_seekstep(int seek_step)
{
    printf("seek_step: %d\n", seek_step);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source file> <object file> \n", argv[0]);
        return 1;
    }
    int fd_src, fd_obj;
    char buffer;
    int ret_src, ret_obj;
    off_t seek_step;
    char ch;
    if ((fd_src = open(argv[1], O_RDWR)) < 0)
    {
        printf("open error fd_src=%d\n", fd_src);
        perror("open a.txt file error");
        return 2;
    }
    ret_src = read_file(fd_src, &buffer, 1);

    seek_step = lseek(fd_src, 0, SEEK_SET);
    print_seekstep(seek_step); // 0
    ret_src = read_file(fd_src, &buffer, 1);

    seek_step = lseek(fd_src, 5, SEEK_SET);
    print_seekstep(seek_step); // 4
    ret_src = read_file(fd_src, &buffer, 1);

    seek_step = lseek(fd_src, -8, SEEK_END);
    print_seekstep(seek_step); //
    ret_src = read_file(fd_src, &ch, 1);

    close(fd_src);
    return 0;
}