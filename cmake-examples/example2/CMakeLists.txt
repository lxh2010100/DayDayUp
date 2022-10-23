# cmake的最低版本要求是2.8
cmake_minimum_required(VERSION 2.8)
# 表示本工程信息，也就是工程名叫demo
project(example2_main)
# 表示最终要生成的elf文件的名字叫main，使用的源文件是main.c testfunc.c
add_executable(main  main.c testfunc.c)