CC=g++
CFLAGS=-std=c++11
WFLAGS=-Wall -g

all: function_pointers.o
	$(CC) $(CFLAGS) $(WFLAGS) -o function_pointers function_pointers.o

function_pointers: function_pointers.o
	$(CC) $(CFLAGS) $(WFLAGS) -o function_pointers function_pointers.o
function_pointers.o: function_pointers.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o function_pointers.o function_pointers.cpp

clean:
	rm *.o
