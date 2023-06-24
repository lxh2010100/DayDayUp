#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    // step 1: create a new process
    pid_t pid = fork();
    if (pid > 0)
        exit(1);
    else
    {
        // step 2: call setpid to get rid of control terminal
        setsid();
        // step 3: change working directory
        chdir("/");
        // step 4: call umask to reset fiel mask
        umask(0);
        // step 5: close 0 1 2 file descriptor
        close(0);
        close(1);
        close(2);
        // step 6: execute user program
        while (1)
        {
            /* code */
        }
    }
    return 0;
}
