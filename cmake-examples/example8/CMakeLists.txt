# cmake的最低版本要求是2.8
cmake_minimum_required(VERSION 3.22.1)
# 表示本工程信息，也就是工程名叫demo
project(example8_main)

# 使用aux_source_directory把src目录下的源文件存列表存放到变量SRC_LIST里
aux_source_directory(./src SRC_LIST)

# 该命令是用来向工程添加多个指定头文件的搜索路径，路径之间用空格分隔
include_directories(./include)

# 表示最终要生成的elf文件的名字叫main，在add_executable里调用SRC_LIST
add_executable(main ${SRC_LIST})

# 这里又出现一个新的命令set，是用于定义变量的，EXECUTABLE_OUT_PATH和PROJECT_SOURCE_DIR是CMake自带的预定义变量，其意义如下，
# EXECUTABLE_OUTPUT_PATH ：目标二进制可执行文件的存放位置
# PROJECT_SOURCE_DIR：工程的根目录
# 所以，这里set的意思是把存放elf文件的位置设置为工程根目录下的bin目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
