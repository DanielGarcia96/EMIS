#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LINK string_to_list(char []);
void print_list(LINK);
int count(LINK);
void free_list(LINK);

int main(void)
{
    LINK   h;
    
    h = string_to_list("ABC");
    printf("The resulting list is\n");
    print_list(h);
    printf("\nThis list has %d elements.\n", count(h));
    
    free_list(h);
    return 0;
}
