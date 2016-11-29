CFLAGS=-Wall -lpthread -g -o
all: prog1
prog1: file1.c file2.o
	gcc $(CFLAGS) prog1 file1.c file2.o
file2.o: file2.c
	gcc -c $(CFLAGS) file2.o file2.c
