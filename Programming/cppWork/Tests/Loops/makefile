CC =g++
CFLAGS=-std=c++11
WFLAGS=-Wall -g

all: for.o
	$(CC) $(CLFAGS) $(WFLAGS) -o for for.o

for: for.o
	$(CC) $(CLFAGS) $(WFLAGS) -o for for.o
for.o: for.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o for.o for.cpp

clean:
	rm *.o
