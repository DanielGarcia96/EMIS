// cin with strings
#include <iostream>
#include <string>

int main()  {
   std::string mystr;
   std::cout << "What's your name? ";
   getline(std::cin, mystr); 
   std::cout << "Hello " << mystr << ".\n";
   std::cout << "What is your favorite team? ";
   getline(std::cin, mystr);
   std::cout << "I like " << mystr << " too!\n";
   return 0;
}
