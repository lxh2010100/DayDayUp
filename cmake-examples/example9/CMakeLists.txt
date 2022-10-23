# cmake的最低版本要求是2.8
cmake_minimum_required(VERSION 3.22.1)
# 表示本工程信息，也就是工程名叫demo
project(example9_main)
# 使用set命令去新建变量来存放需要的源文件
set(SRC_LIST ${PROJECT_SOURCE_DIR}/testfunc/testfunc.c)
# add_library: 生成动态库或静态库 第1个参数指定库的名字 第2个参数决定是动态还是静态 如果没有就默认静态 第3个参数指定生成库的源文件
add_library(testfunc_shared SHARED ${SRC_LIST})
add_library(testfunc_static STATIC ${SRC_LIST})
# set_target_properties: 设置最终生成的库的名称，还有其它功能，如设置库的版本号等等
set_target_properties(testfunc_shared PROPERTIES OUTPUT_NAME "testfunc")
set_target_properties(testfunc_static PROPERTIES OUTPUT_NAME "testfunc")
# LIBRARY_OUTPUT_PATH: 库文件的默认输出路径，这里设置为工程目录下的lib目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
