default: cmdscan.o
	gcc -Wall -g -o ysh cmdscan.o ysh.c
cmdscan.o:
	gcc -Wall -g -c -o cmdscan.o cmdscan.c
clean:
	rm cmdscan.o
redo:
	rm cmdscan.o
	gcc -Wall -g -c -o cmdscan.o cmdscan.c 
	gcc -Wall -g -o ysh cmdscan.o ysh.c
