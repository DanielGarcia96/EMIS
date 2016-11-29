#include <string>
#include <iostream>

int main(void)
{
   std::string s1 = "Lee King";
   std::string s2("Rea King");
   
   
   std::cout << s1.length() << std::endl;
   std::cout << s1.max_size() << std::endl;
   std::cout << s1.capacity() << std::endl;
   return 0;
}
