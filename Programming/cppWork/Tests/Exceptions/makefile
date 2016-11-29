CC =-g++
WFLAGS =-Wall -g
CFLAGS =-std=c++11

all: try_catch.o std_exceptions.o bad_alloc_ex.o
	$(CC) $(WFLAGS) $(CLAGS) -o try_catch try_catch.o
	$(CC) $(WFLAGS) $(CLAGS) -o std_exceptions std_exceptions.o
	$(CC) $(WFLAGS) $(CLAGS) -o bad_alloc_ex bad_alloc_ex.o
	
try_catch: try_catch.o
	$(CC) $(WFLAGS) $(CLAGS) -o try_catch try_catch.o
try_catch.o:
	$(CC) $(WFLAGS) $(CLAGS) -c -o try_catch.o try_catch.cpp

std_exceptions:std_exceptions.o
	$(CC) $(WFLAGS) $(CLAGS) -o std_exceptions std_exceptions.o
std_exceptions.o:
	$(CC) $(WFLAGS) $(CLAGS) -c -o std_exceptions.o std_exceptions.cpp

bad_alloc_ex: bad_alloc_ex.o
	$(CC) $(WFLAGS) $(CLAGS) -o bad_alloc_ex bad_alloc_ex.o
bad_alloc_ex.o:
	$(CC) $(WFLAGS) $(CLAGS) -c -o bad_alloc_ex.o bad_alloc_ex.cpp

clean:
	rm *.o
