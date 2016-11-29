// using standard exceptions
#include <iostream>
#include <exception>
using namespace std;

class myexception: public std::exception  {
   virtual const char* what() const throw()  {
      return "My exception happened";
   }
} myex;

int main()  {
   try  {
      throw myex;
   } catch(exception& e)  {
      std::cout << e.what() << '\n';
   }
   return 0;
}
