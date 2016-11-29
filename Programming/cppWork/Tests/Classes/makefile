CC =g++
CFLAGS=-std=c++11
WFLAGS=-Wall -g

all: class_ex.o constructors.o overloading_constructors.o uniform_initialization.o member_initialization.o pointer_class.o
	$(CC) $(CFLAGS) $(WFLAGS) -o class_ex class_ex.o
	$(CC) $(CFLAGS) $(WFLAGS) -o constructors constructors.o
	$(CC) $(CFLAGS) $(WFLAGS) -o overloading_constructors overloading_constructors.o
	$(CC) $(CFLAGS) $(WFLAGS) -o uniform_initialization uniform_initialization.o
	$(CC) $(CFLAGS) $(WFLAGS) -o member_initialization member_initialization.o
	$(CC) $(CFLAGS) $(WFLAGS) -o pointer_class pointer_class.o

class_ex: class_ex.o
	$(CC) $(CFLAGS) $(WFLAGS) -o class_ex class_ex.o
class_ex.o: class_ex.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o class_ex.o class_ex.cpp

constructors: constructors.o
	$(CC) $(CFLAGS) $(WFLAGS) -o constructors constructors.o
constructors.o: constructors.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o constructors.o constructors.cpp

overloading_constructors: overloading_constructors.o
	$(CC) $(CFLAGS) $(WFLAGS) -o overloading_constructors overloading_constructors.o
overloading_constructors.o: overloading_constructors.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o overloading_constructors.o overloading_constructors.cpp

uniform_initialization: uniform_initialization.o
	$(CC) $(CFLAGS) $(WFLAGS) -o uniform_initialization uniform_initialization.o
uniform_initialization.o: uniform_initialization.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o uniform_initialization.o uniform_initialization.cpp

member_initialization: member_initialization.o
	$(CC) $(CFLAGS) $(WFLAGS) -o member_initialization member_initialization.o
member_initialization.o: member_initialization.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o member_initialization.o member_initialization.cpp

pointer_class: pointer_class.o
	$(CC) $(CFLAGS) $(WFLAGS) -o pointer_class pointer_class.o
pointer_class.o: pointer_class.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o pointer_class.o pointer_class.cpp

clean:
	rm *.o
