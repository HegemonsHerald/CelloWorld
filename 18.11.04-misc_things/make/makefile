# my standard extensions are
.SUFFIXES: .o .c

# my object files are
objects = add.o print.o subtract.o

# make a file main from main.c and libstuff.a
main: main.c libstuff.a
	gcc -o main main.c -L. -lstuff

# make a file libstuff.a from the object files
libstuff.a: $(objects)
	ar rcs $@ $(objects)

# make any file *.o from any file *.c
.c.o:
	gcc -c -fpic $<
