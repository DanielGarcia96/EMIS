#include <stdio.h>

#define LIMIT 4000000

int main(void)
{
    // Set up my first values
    int a = 1, b = 2, c = 3, sum = 2;
    
    // Keep repeating the process of getting the next term
    // until the term that you encounter is over 4 million
    while(c < LIMIT)
    {
        // Calculate the next term
        c = a+b;
        // Store the value of the second to last term
        a = b;
        // Store the value of the last term
        b = c;

        // Check to see if the value you just calculated is even
        // and add it to the sum if it is.
        if ( c % 2 == 0 )
            sum += c;
    }

    // Print the result
    printf("%d\n", sum);
    return 0;
}
