set(LIB_SRCS hello.c)
add_library(hello_shared SHARED ${LIB_SRCS})
add_library(hello_static STATIC ${LIB_SRCS})
