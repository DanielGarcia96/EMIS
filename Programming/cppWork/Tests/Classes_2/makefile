CC=g++
CFLAGS=-Wall -g
WFLAGS=-std=c++11

all: overloading_operators.o non-member_overloads.o this.o static_members.o const_members.o const_objects.o
	$(CC) $(CFLAGS) $(WFLAGS) -o overloading_operators overloading_operators.o
	$(CC) $(CFLAGS) $(WFLAGS) -o non-member_overloads non-member_overloads.o
	$(CC) $(CFLAGS) $(WFLAGS) -o this this.o
	$(CC) $(CFLAGS) $(WFLAGS) -o static_members static_members.o
	$(CC) $(CFLAGS) $(WFLAGS) -o const_members const_members.o
	$(CC) $(CFLAGS) $(WFLAGS) -o const_objects const_objects.o

overloading_operators: overloading_operators.o
	$(CC) $(CFLAGS) $(WFLAGS) -o overloading_operators overloading_operators.o
overloading_operators.o: overloading_operators.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o overloading_operators.o overloading_operators.cpp

non-member_overloads: non-member_overloads.o
	$(CC) $(CFLAGS) $(WFLAGS) -o non-member_overloads non-member_overloads.o
non-member_overloads.o: non-member_overloads.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o non-member_overloads.o non-member_overloads.cpp

this: this.o
	$(CC) $(CFLAGS) $(WFLAGS) -o this this.o
this.o: this.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o this.o this.cpp

static_members: static_members.o
	$(CC) $(CFLAGS) $(WFLAGS) -o static_members static_members.o
static_members.o: static_members.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o static_members.o static_members.cpp

const_members: const_members.o
	$(CC) $(CFLAGS) $(WFLAGS) -o const_members const_members.o
const_members.o: const_members.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o const_members.o const_members.cpp

const_objects: const_objects.o
	$(CC) $(CFLAGS) $(WFLAGS) -o const_objects const_objects.o
const_objects.o: const_objects.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o const_objects.o const_objects.cpp

clean:
	rm *.o
