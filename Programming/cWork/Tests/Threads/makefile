all: methread

methread: methread.o
	gcc -Wall -g -o methread methread.o -lpthread

methread.o: methread.c
	gcc -Wall -c -g -o methread.o methread.c -lpthread

clean:
	rm *.o
