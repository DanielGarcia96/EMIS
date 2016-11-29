// i/o example

#include <iostream>

int main()  {
   int i;
   std::cout << "Please enter an integer value: ";
   std::cin >> i;
   std::cout << "The value you entered is " << i;
   std::cout << " and its double is " << i*2 << ".\n";
   return 0;
}
