#include "bit_include.h"

int main(void)
{
    printf("O_RDONLY: ");
    bit_print(O_RDONLY);

    printf("O_WRONLY: ");
    bit_print(O_WRONLY);

    printf("O_RDWR:   ");
    bit_print(O_RDWR);

    printf("O_APPEND: ");
    bit_print(O_APPEND);
    return 0;
}
