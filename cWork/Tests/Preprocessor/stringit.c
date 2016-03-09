#include <stdio.h>
#define message_for(a, b)  \
        printf(#a " and " #b ": We love you!\n")
#define print_this(a)  \
        printf(#a "\n")

int main(void)
{
    //message_for(Carole, Debra);
    ////////////////printf("\n");
    print_this(robert);
    return 0;
}
