#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <wait.h>
int main(int argc, char **argv)
{
    int fd[2] = {0};
    char buffer[32];
    pipe(fd);
    printf("fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
    if (fork())
    {
        int status;
        close(fd[0]);
        write(fd[1], "hello", 5);
        close(fd[1]);
        wait(&status);
        exit(1);
    }
    else
    {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("buffer is %s\n", buffer);
        close(fd[0]);
        exit(0);
    }
    return 0;
}
