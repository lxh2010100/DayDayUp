cmake_minimum_required(VERSION 3.22.1)
project(example14_main)
set(SRC_LIST ./main.c)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 加一些编译选项，如-Wall，-std=c++11等，就可以使用add_compile_options来进行操作。
add_compile_options(-std=c11 -Wall -g)
add_executable(main ${SRC_LIST})
