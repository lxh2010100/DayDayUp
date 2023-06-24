cmake_minimum_required(VERSION 2.8.12)

project(kernel-sycalls_${APP})

enable_language(C CXX)

set(directory ${APP})

include_directories(${CMAKE_SOURCE_DIR}/../googletest/include/)

file(GLOB_RECURSE  SRCS ${APP_PATH}/${directory}/*.cpp)

link_directories(${CMAKE_SOURCE_DIR}/../googletest/lib)

foreach(code ${SRCS})
    get_filename_component(file_name ${code} NAME_WE)
    message("file_name = ${file_name}")
    set(target_name ${directory}_${file_name})
    message("target_name = ${target_name}")
    add_executable(${target_name} ${code})
    target_link_libraries(${target_name} libgtest.a libgtest_main.a)
endforeach()


