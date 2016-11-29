#include <stdio.h>
#include <string.h>

#define LIMIT 1000

int palindrome(int n);

int main(void)
{
    // Set up my highest variable, and factors
    int highest = 0, a = 1, b;

    // For all possible combinations a and b
    while( a < LIMIT)
    {
        b = 1;
        while( b < LIMIT )
        {
            // If the new product is larger than the highest
            // and is also a palindrome, it's the new highest
            int new = a*b;
            if( new > highest && palindrome(new) )
                highest = new;
            b++;
        }
        a++;
    }

    // Print the highest
    printf("%d\n", highest);
    return 0;
}

int palindrome(int n)
{
    char numstr[10] = "";
    sprintf(numstr, "%d", n);
    int l = strlen(numstr);
    int h = l/2, i;

    // If the character at i and len-i-1 are not the same,
    // then the string is not a palindrome.
    for(i = 0; i < h; i++)
        if(numstr[i] != numstr[l-i-1])
            return 0;
    return 1;
}
