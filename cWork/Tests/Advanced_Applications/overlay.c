#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int    choice = 0;
    
    printf("%s\n%s\n%s",
           "The parent process will be overlaid.",
           "You have a choice.",
           "Input 1 or 2: ");
    scanf("%d", &choice);
    putchar('\n');
    if (choice == 1)
        execl("pgm1", "pgm1", "a", "b", "c", NULL);
    if (choice == 2)
        execl("pgm2", "pgm2", "1", "2", "3", "go", NULL);
    printf("ERROR: You did not input 1 or 2.\n");
    return 0;
}
