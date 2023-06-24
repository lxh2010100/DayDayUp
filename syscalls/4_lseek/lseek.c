#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void) 
{
	int fd, n;
	char buf[] = "hello world test \n";
	char ch;

	fd = open("test.txt", O_RDWR|O_CREAT, 0644);
	if(fd < 0)
	{
		perror("open lseek.txt error");
		exit(1);
	}
	//使用fd对打开的文件进行写操作，写完后文件指针位置位于文件结尾处
	write(fd, buf, strlen(buf));   
	/*
    注意：读和写操作使用同一偏移位置，由于文件指针位于末尾，因此后面的read就会读不到数据了
	这一行的目的是把文件指针移动到文件头位置，这样下面的代码就能读到数据了
	*/
	n = lseek(fd , 0 , SEEK_SET);
	if(n == -1)
	{
	    perror("lseek fail");
	    exit(1);
	}
	printf("n=%d\n",n );
	//lseek移到文件开头，read就能读取到数据了
	while((n = read(fd, &ch, 1)))
	{
		if(n < 0)
		{
			perror("read error");
			exit(1);
		}
		//将文件内容按字节读出，写到屏幕
		write(STDOUT_FILENO, &ch, n);  
	}
	close(fd);
	return 0;
}
