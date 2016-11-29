#include <stdio.h>

int main(void)
{
    // Start at the highest factor
    int n = 20;

    // Until we've found the value, continue looping
    while(1)
    {
        // Set up a control variable and a flag to see
        // if the number is divisible by 1 through 20
        int i, failed = 0;
        for(i = 1; i < 20; i++)
        {
            if(n % i != 0)
            {
                // If it's not divisible by any of them, set the flag
                failed = 1;
                break;
            }
        }

        // If we've found our value, break out of the loop
        if(!failed)
            break;

        // Increment and continue
        n++;
    }

    // Print the result
    printf("%d\n", n);
    return 0;
}
