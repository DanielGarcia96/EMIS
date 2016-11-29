CC = gcc

CFLAGS += -Wall
CFLAGS += -g

all: list.o
	$(CC) $(CFLAGS) -o LIST list.o test.c

list.o:
	$(CC) $(CFLAGS) -c -o list.o list.c
