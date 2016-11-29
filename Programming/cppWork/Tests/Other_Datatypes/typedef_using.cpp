#include <iostream>
using namespace std;

int main()  {
   using C = char;
   //same as, typedef char C;
   using WORD = unsigned int;
   //same as, typedef unsigned int WORD ;
   using pChar = char *;
   //same as, typedef char * pChar;
   using field = char[50];
   //same as typedef char[50] field;

   C mychar, anotherchar, *ptc1;
   mychar = anotherchar = 'A';
   ptc1 = &mychar;

   WORD myword = 255;
   
   pChar ptc2 = ptc1;
   field name = "Daniel Garcia";

   cout << mychar << " " << anotherchar << " " << *ptc1 << " " << *ptc2 << " " << myword << " " << name << endl;

   return 0;
}
