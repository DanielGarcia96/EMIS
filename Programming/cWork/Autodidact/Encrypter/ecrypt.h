#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define  BUF        1024

#define  ECY        1
#define  DCY        2
#define  UNK        3

int encrypt(int fd, int cipher);
int decrypt(int fd, int cipher);
void e_alg(int cipher, char buffer[]);
void d_alg(int cipher, char buffer[]);
