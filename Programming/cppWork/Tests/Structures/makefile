CC =g++
CFLAGS =-std=c++11
WFLAGS =-Wall -g

all: struct.o
	$(CC) $(CLFAGS) $(WFLAGS) -o struct struct.o

struct: struct.o
	$(CC) $(CLFAGS) $(WFLAGS) -o struct struct.o
struct.o: struct.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o struct.o struct.cpp

clean:
	rm *.o
