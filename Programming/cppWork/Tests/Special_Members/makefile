CC=g++
WFLAGS=-Wall -g
CFLAGS=-std=c++11

all: default_constructors.o destructors.o
	$(CC) $(CFLAGS) $(WFLAGS) -o default_constructors default_constructors.o
	$(CC) $(CFLAGS) $(WFLAGS) -o destructors destructors.o

default_constructors: default_constructors.o
	$(CC) $(CFLAGS) $(WFLAGS) -o default_constructors default_constructors.o
default_constructors.o: default_constructors.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o default_constructors.o default_constructors.cpp

destructors: destructors.o
	$(CC) $(CFLAGS) $(WFLAGS) -o destructors destructors.o
destructors.o: destructors.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o destructors.o destructors.cpp

clean:
	rm *.o
