#include <stdio.h>
void mylib(void);

int main(void)
{
    mylib();
    return 0;
}

// gcc - c mylib.c - o mylib.o
// ar cr libmylib.a mylib.o
// gcc main.c -lmylib -L . -o main_static

// ➜  6_lib git:(master) ✗ gcc -c -fpic mylib.c
// ➜  6_lib git:(master) ✗ gcc -shared -o libmylib.so mylib.o
// ➜  6_lib git:(master) ✗ gcc main.c -lmylib -L . -o main_shared
// ➜  6_lib git:(master) ✗ ./main_shared
// ./main_shared: error while loading shared libraries: libmylib.so: cannot open shared object file: No such file or directory
// ➜  6_lib git:(master) ✗ ls
// libmylib.a  libmylib.so  main.c  main_shared  main_static  mylib.c  mylib.o
// ➜  6_lib git:(master) ✗ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/luxihua/Desktop/DayDayUp/Linux_C/6_lib
// ➜  6_lib git:(master) ✗ echo $PATH
// /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/luxihua/.local/bin:/home/luxihua/.fig/bin:/home/linuxbrew/.linuxbrew/Homebrew/bin/
// ➜  6_lib git:(master) ✗ echo $LD_LIBRARY_PATH
// :/home/luxihua/Desktop/DayDayUp/Linux_C/6_lib
// ➜  6_lib git:(master) ✗ ./main_shared
// this is my library

// vim /etc/ld.so.conf.d
// /home/luxihua/Desktop/DayDayUp/Linux_C/6_lib
// sudo ldconfig