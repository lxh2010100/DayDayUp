# cmake的最低版本要求是2.8
cmake_minimum_required(VERSION 2.8)
# 表示本工程信息，也就是工程名叫demo
project(example3_main)
# 使用aux_source_directory把当前目录下的源文件存列表存放到变量SRC_LIST里
aux_source_directory(. SRC_LIST)
# 表示最终要生成的elf文件的名字叫main，在add_executable里调用SRC_LIST
add_executable(main  ${SRC_LIST})