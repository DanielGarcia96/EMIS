#include "bit_include.h"

int main(void)
{
//    printf("O_RDONLY: ");
//    bit_print(O_RDONLY);

//    printf("O_WRONLY: ");
//    bit_print(O_WRONLY);

//    printf("O_RDWR:   ");
//    bit_print(O_RDWR);

//    printf("O_APPEND: ");
//    bit_print(O_APPEND);

    int a = 4-5;
    int c = 0;
    c = ~c;
    if ( a < 0 )
       a -= (2*a);

    printf("%d\n", a);
    return 0;
}
