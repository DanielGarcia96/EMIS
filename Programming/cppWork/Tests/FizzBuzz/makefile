CC =g++
CFLAGS=-std=c++11
WFLAGS=-Wall -g

all: fizzbuzz.o
	$(CC) $(CLFAGS) $(WFLAGS) -o fizzbuzz fizzbuzz.o

fizzbuzz: fizzbuzz.o
	$(CC) $(CLFAGS) $(WFLAGS) -o fizzbuzz fizzbuzz.o
fizzbuzz.o: fizzbuzz.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o fizzbuzz.o fizzbuzz.cpp

clean:
	rm *.o
