CC=g++
CFLAGS=-std=c++11
WFLAGS=-Wall -g

all: new_delete.o
	$(CC) $(CFLAGS) $(WFLAGS) -o new_delete new_delete.o

new_delete: new_delete.o
	$(CC) $(CFLAGS) $(WFLAGS) -o new_delete new_delete.o
new_delete.o: new_delete.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o new_delete.o new_delete.cpp

clean:
	rm *.o
