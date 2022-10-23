cmake_minimum_required(VERSION 3.22.1)
project(demo2)
add_compile_options(-g -static)

if(${OPT1} STREQUAL "HELLO1")
  message("OPT1=HELLO1")
  add_executable(hello1 src/hello1.c)
elseif(${OPT1} STREQUAL "HELLO2")
  message("OPT1=HELLO2")
  add_executable(hello2 src/hello2.c)
else()
  message(FATAL_ERROR "OPT1=${OPT1}")
endif()

