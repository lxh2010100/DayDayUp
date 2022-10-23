# cmake的最低版本要求是2.8
cmake_minimum_required(VERSION 3.22.1)
# 表示本工程信息，也就是工程名叫demo
project(example6_main)
# # 该命令是用来向工程添加多个指定头文件的搜索路径，路径之间用空格分隔
# include_directories(./test_func ./test_func1)
# 使用aux_source_directory把./test_func下的源文件存列表存放到变量SRC_LIST里
aux_source_directory(./test_func SRC_LIST)
# 使用aux_source_directory把./test_func1下的源文件存列表存放到变量SRC_LIST1里
aux_source_directory(./test_func1 SRC_LIST1)
# 表示最终要生成的elf文件的名字叫main，在add_executable里调用SRC_LIST
add_executable(main main.c ${SRC_LIST} ${SRC_LIST1})
