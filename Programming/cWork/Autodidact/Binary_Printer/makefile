CC =gcc
WFLAGS =-Wall -g

all: bin_print.o
	$(CC) $(WFLAGS) -o bin_print bin_print.o

bin_print: bin_print.o
	$(CC) $(WFLAGS) -o bin_print bin_print.o
bin_print.o: bin_print.cpp
	$(CC) $(WFLAGS) -c -o bin_print.o bin_print.cpp

clean:
	rm *.o
