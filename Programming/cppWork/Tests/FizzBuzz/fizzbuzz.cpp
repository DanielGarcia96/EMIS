#include <iostream>

#define LIMIT 100

int main()  {
   for (int i=0; i<LIMIT; i++)  {
      if ( i%5 == 0 && i%3 == 0 )  {
         std::cout << "FizzBuzz = " << i << std::endl;
         continue;
      }
      if ( i%3 == 0 )  {
         std::cout << "Fizz = " << i << std::endl;
         continue;
      }
      if ( i%5 == 0 )  {
         std::cout << "Buzz = " << i << std::endl;
         continue;
      }
   }
   return 0;
}
