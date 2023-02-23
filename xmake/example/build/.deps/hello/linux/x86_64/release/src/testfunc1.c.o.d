{
    files = {
        "src/testfunc1.c"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64"
        }
    },
    depfiles_gcc = "testfunc1.o: src/testfunc1.c\
"
}