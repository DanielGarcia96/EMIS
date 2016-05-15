#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void bit_print(int a);
int pack(char a, char b, char c, char d);
char unpack(int p, int k);
