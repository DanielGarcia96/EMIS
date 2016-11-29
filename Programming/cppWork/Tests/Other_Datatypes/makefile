CC=g++
CFLAGS=-std=c++11
WFLAGS=-Wall -g

all: typedef_using.o anon_unions.o class_enums.o
	$(CC) $(CFLAGS) $(WFLAGS) -o typedef_using typedef_using.o
	$(CC) $(CFLAGS) $(WFLAGS) -o anon_unions anon_unions.o
	$(CC) $(CFLAGS) $(WFLAGS) -o class_enums class_enums.o

typedef_using: typedef_using.o
	$(CC) $(CFLAGS) $(WFLAGS) -o typedef_using typedef_using.o
typedef_using.o: typedef_using.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o typedef_using.o typedef_using.cpp

anon_unions: anon_unions.o
	$(CC) $(CFLAGS) $(WFLAGS) -o anon_unions anon_unions.o
anon_unions.o: anon_unions.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o anon_unions.o anon_unions.cpp

class_enums: class_enums.o
	$(CC) $(CFLAGS) $(WFLAGS) -o class_enums class_enums.o
class_enums.o: class_enums.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o class_enums.o class_enums.cpp

clean:
	rm *.o
