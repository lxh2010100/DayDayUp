cmake_minimum_required(VERSION 3.22.1)

project(array)

include_directories(./include)

add_compile_options("-g")


aux_source_directory(./src SRC_LISTS)

add_executable(main ${SRC_LISTS} main.c)