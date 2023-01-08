#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
struct stat buf;
int main(int argc, char **argv)
{
    int fd = open(argv[1], O_WRONLY);
    int ret = 0;
    if (fd != -1)
    {
        ret = fstat(fd, &buf);
        printf("ret=%d\n", ret);
        printf("buf.st_ino=%ld\n", buf.st_ino);
        printf("buf.st_dev=%ld\n", buf.st_dev);
    }
    printf("now test stdin stdout stderr\n");
    for (size_t i = 0; i < 3; i++)
    {
        ret = fstat(i, &buf);
        printf("ret=%d\n", ret);
        printf("buf.st_ino=%ld\n", buf.st_ino);
        printf("buf.st_dev=%ld\n", buf.st_dev);
    }

    return 0;
}