all: assign4 assign4final

assign4: assign4.c nqueens_library.o
	gcc -Wall -g -o assign4 assign4.c nqueens_library.o -lpthread

assign4final: assign4final.c nqueens_library.o
	gcc -Wall -g -o assign4final assign4final.c nqueens_library.o -lpthread

nqueens_library.o: nqueens_library.c
	gcc -Wall -c -g -o nqueens_library.o nqueens_library.c -lm -lpthread

run1: assign4
	assign4 12

run2: assign4final
	assign4final 12

clean:
	rm *.o
