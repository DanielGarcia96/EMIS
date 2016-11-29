CC = gcc
CFLAGS += -Wall -g
OBJ = queue.o
NAME = -o QUEUE
BIN = -c

all: queue
	$(CC) $(CFLAGS) $(NAME) $(OBJ) main.c
queue:
	$(CC) $(CFLAGS) $(BIN) -o $(OBJ) $(OBJ:.o=.c)
