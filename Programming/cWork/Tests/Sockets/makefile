CC=gcc
CFLAGS=-Wall -g

all: client.o server.o
	$(CC) $(CFLAGS) -o client client.o
	$(CC) $(CFLAGS) -o server server.o

client: client.o
	$(CC) $(CFLAGS) -o client client.o
client.o: client.c
	$(CC) $(CFLAGS) -c -o client.o client.c

server: server.o
	$(CC) $(CFLAGS) -o server server.o
server.o: server.c
	$(CC) $(CFLAGS) -c -o server.o server.c

clean_all:
	rm *.o
clean_client:
	rm client.o
clean_server:
	rm server.o
