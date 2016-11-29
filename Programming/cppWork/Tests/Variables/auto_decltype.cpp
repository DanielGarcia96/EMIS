// testing out keywords auto and decltype
#include <iostream>
using namespace std;

int main()  {
   int foo = 10;
   auto bar = foo;
   decltype(foo) newbar;
   newbar = 20;

   cout << foo << " " << bar << " " << newbar << endl;
   
   return 0;
}
