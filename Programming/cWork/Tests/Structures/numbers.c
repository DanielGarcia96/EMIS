#include <stdio.h>

typedef union int_or_float {
   int     i;
   float   f;
} number;

int main(void)
{
    number n;
    union int_or_float x;

    n.i = 4444;
    printf("i: %10d	f: %16.10e\n", n.i, n.f);
    n.f = 4444.0;
    printf("i: %10d	f: %16.10e\n", n.i, n.f);

    x.i = 5555;
    printf("i: %10d     f: %16.10e\n", x.i, x.f);
    x.f = 5555.0;
    printf("i: %10d     f: %16.10e\n", x.i, x.f);
    return 0;
}
