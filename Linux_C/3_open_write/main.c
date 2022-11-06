#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <source file> <object file> \n", argv[0]);
        return 1;
    }
    int fd_src, fd_obj;
    char buffer[1000] = {0};
    int ret_src, ret_obj;
    if ((fd_src = open(argv[1], O_RDWR)) < 0)
    {
        printf("open error fd_src=%d\n", fd_src);
        perror("open a.txt file error");
        return 2;
    }
    // if ((fd_obj = open(argv[2], O_WRONLY | O_CREAT, 0666) < 0)）
    // 这种写法由于优先级问题 = 优先级低于 < 导致fd_obj一直是0
    // 坑啊
    if ((fd_obj = open(argv[2], O_WRONLY | O_CREAT, 0666)) < 0)
    {
        printf("open error fd_obj=%d\n", fd_obj);
        return 3;
    }
    perror("open b.txt");
    printf("fd_obj=%d\n", fd_obj);

    while ((ret_src = read(fd_src, buffer, sizeof(buffer))) != 0)
    {
        ret_obj = write(fd_obj, buffer, ret_src);
        printf("ret_src = %d\n", ret_src);
        printf("ret_obj = %d\n", ret_obj);
    }
    close(fd_src);
    close(fd_obj);
    return 0;
}