#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        perror("fork failed\n");
        return -1;
    }
    else if (pid > 0)
    {
        printf("this is parent process the pid is %d,he`s child pid is %d\n", getpid(), pid);
        sleep(1);
    }
    else
    {
        printf("this is a child process the pid is %d, he`s parent pid is %d\n", getpid(), getppid());
    }
    return 0;
}
