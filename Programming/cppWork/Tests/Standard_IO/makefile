CC =g++
WFLAGS =-Wall -g
CFLAGS =-std=c++11

all: standcout.o standcin.o getline.o stringstreams.o file.o file_size.o read_binary.o
	$(CC) $(WFLAGS) $(CFLAGS) -o standcout standcout.o
	$(CC) $(WFLAGS) $(CFLAGS) -o standcin standcin.o
	$(CC) $(WFLAGS) $(CFLAGS) -o getline getline.o
	$(CC) $(WFLAGS) $(CFLAGS) -o stringstreams stringstreams.o
	$(CC) $(WFLAGS) $(CFLAGS) -o file file.o
	$(CC) $(WFLAGS) $(CFLAGS) -o file_size file_size.o
	$(CC) $(WFLAGS) $(CFLAGS) -o read_binary read_binary.o

standcout: standcout.o
	$(CC) $(WFLAGS) $(CFLAGS) -o standcout standcout.o

standcout.o: standcout.cpp
	$(CC) $(WFLAGS) $(CFLAGS) -c -o standcout.o standcout.cpp

standcin: standcin.o
	$(CC) $(WFLAGS) $(CFLAGS) -o standcin standcin.o

standcin.o: standcin.cpp
	$(CC) $(WFLAGS) $(CFLAGS) -c -o standcin.o standcin.cpp

getline: getline.o
	$(CC) $(WFLAGS) $(CFLAGS) -o getline getline.o

getline.o: getline.cpp
	$(CC) $(WFLAGS) $(CFLAGS) -c -o getline.o getline.cpp

stringstreams: stringstreams.o
	$(CC) $(WFLAGS) $(CFLAGS) -o stringstreams stringstreams.o

stringstreams.o: stringstreams.cpp
	$(CC) $(WFLAGS) $(CFLAGS) -c -o stringstreams.o stringstreams.cpp

file: file.o
	$(CC) $(WFLAGS) $(CFLAGS) -o file file.o

file.o: file.cpp
	$(CC) $(WFLAGS) $(CFLAGS) -c -o file.o file.cpp

file_size: file_size.o
	$(CC) $(WFLAGS) $(CFLAGS) -o file_size file_size.o
	
file_size.o: file_size.cpp
	$(CC) $(WFLAGS) $(CFLAGS) -c -o file_size.o file_size.cpp

read_binary: read_binary.o
	$(CC) $(WFLAGS) $(CFLAGS) -o read_binary read_binary.o

read_binary.o: read_binary.cpp
	$(CC) $(WFLAGS) $(CFLAGS) -c -o read_binary.o read_binary.cpp

clean:
	rm *.o
