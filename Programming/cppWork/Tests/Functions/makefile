CC =g++
CFLAGS =-std=c++11
WFLAGS =-Wall -g

all: pass_by_reference.o const_values.o inline_functions.o default_values.o templates.o
	$(CC) $(CFLAGS) $(WFLAGS) -o pass_by_reference pass_by_reference.o
	$(CC) $(CFLAGS) $(WFLAGS) -o const_values const_values.o
	$(CC) $(CFLAGS) $(WFLAGS) -o inline_functions inline_functions.o
	$(CC) $(CFLAGS) $(WFLAGS) -o default_values default_values.o
	$(CC) $(CFLAGS) $(WFLAGS) -o templates templates.o
	
pass_by_reference: pass_by_reference.o
	$(CC) $(CFLAGS) $(WFLAGS) -o pass_by_reference pass_by_reference.o
pass_by_reference.o: pass_by_reference.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o pass_by_reference.o pass_by_reference.cpp

const_values: const_values.o
	$(CC) $(CFLAGS) $(WFLAGS) -o const_values const_values.o
const_values.o: const_values.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o const_values.o const_values.cpp

inline_functions: inline_functions.o
	$(CC) $(CFLAGS) $(WFLAGS) -o inline_functions inline_functions.o
inline_functions.o: inline_functions.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o inline_functions.o inline_functions.cpp

default_values: default_values.o
	$(CC) $(CFLAGS) $(WFLAGS) -o default_values default_values.o
default_values.o: default_values.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o default_values.o default_values.cpp

templates: templates.o
	$(CC) $(CFLAGS) $(WFLAGS) -o templates templates.o
templates.o: templates.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o templates.o templates.cpp

clean:
	rm *.o
