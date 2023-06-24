#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char **argv)
{
    int i = 0;
    pid_t pid;
    int status;
    int ret = 0;
    if (!fork())
    {
        /*child */
        i++;
        printf("this is child process [%d]\n", getpid());
        sleep(1);
        return 2;
    }
    else
    {
        /*parent*/
        i++;
        printf("this is parent process [%d]\n", getpid());
        ret = wait(&status);
        if (WIFEXITED(status))
        {
            printf(" child exited status with %d, and his children pid is %d\n", WEXITSTATUS(status), ret);
        }
    }
    printf("i=%d,it`s pid = %d\n", i, getpid());
    return 0;
}