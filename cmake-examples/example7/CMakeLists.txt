# cmake的最低版本要求是2.8
cmake_minimum_required(VERSION 3.22.1)
# 表示本工程信息，也就是工程名叫demo
project(example7_main)
# 这个命令可以向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制的存放位置
add_subdirectory(./src)
