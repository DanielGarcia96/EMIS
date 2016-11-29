CC = gcc

CFLAGS += -g
CFLAGS += -Wall

all: queue debug bit_print
	$(CC) $(CFLAGS) -o QUEUE queue.o debug.o bit_print.o main.c
queue:
	$(CC) $(CFLAGS) -c -o queue.o queue.c
bit_print:
	$(CC) $(CFLAGS) -c -o bit_print.o bit_print.c
debug:
	$(CC) $(CFLAGS) -c -o debug.o debug.c
