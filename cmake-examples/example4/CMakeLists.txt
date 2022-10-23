# cmake的最低版本要求是2.8
cmake_minimum_required(VERSION 3.22.1)
# 表示本工程信息，也就是工程名叫demo
project(example4_main)
# 使用set命令去新建变量来存放需要的源文件
set(SRC_LIST ./main.c ./testfunc.c ./testfunc1.c)
# 表示最终要生成的elf文件的名字叫main，在add_executable里调用SRC_LIST
add_executable(main ${SRC_LIST})
