CC =g++
CFLAGS =-std=c++11
WFLAGS =-Wall -g

all: declaring.o initialization.o auto_decltype.o
	$(CC) $(CFLAGS) $(WFLAGS) -o declaring declaring.o
	$(CC) $(CFLAGS) $(WFLAGS) -o initialization initialization.o
	$(CC) $(CFLAGS) $(WFLAGS) -o auto_decltype auto_decltype.o
	
declaring: declaring.o
	$(CC) $(CFLAGS) $(WFLAGS) -o declaring declaring.o
declaring.o: declaring.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o declaring.o declaring.cpp

initialization: initialization.o
	$(CC) $(CFLAGS) $(WFLAGS) -o initialization initialization.o
initialization.o: initialization.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o initialization.o initialization.cpp

auto_decltype: auto_decltype.o
	$(CC) $(CFLAGS) $(WFLAGS) -o auto_decltype auto_decltype.o
auto_decltype.o: auto_decltype.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o auto_decltype.o auto_decltype.cpp

clean:
	rm *.o
