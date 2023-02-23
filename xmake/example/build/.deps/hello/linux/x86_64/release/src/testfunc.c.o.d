{
    files = {
        "src/testfunc.c"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64"
        }
    },
    depfiles_gcc = "testfunc.o: src/testfunc.c\
"
}