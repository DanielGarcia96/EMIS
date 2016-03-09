all: profile_bin
	gcc -Wall -g -o profile profile.o main.c
	mv profile ../product
	mv profile.o ../bin
profile_bin:
	gcc -Wall -g -c -o profile.o profile.c
