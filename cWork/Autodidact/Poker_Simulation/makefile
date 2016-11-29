CC = gcc
CFLAGS = -Wall -g
POBJ = poker.o
SOBJ = SIM

all: poker
	$(CC) $(CFLAGS) -o $(SOBJ) $(POBJ) main.c
	
poker:
	$(CC) $(CFLAGS) -o $(POBJ) -c poker.c
