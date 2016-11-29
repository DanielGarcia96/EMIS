#include <iostream>
#include <string>
using namespace std;

//Using const forbids you from modifying the contents of 
//the variables you have passed.
//This is because functions need to insure they don't
//change any values of large variables the caller might
//have to pass by reference.
string concatenate(const string& a, const string& b)  {
  return a+b;
}

int main()  {
   string a = "string a ";
   string b = "string b";
   string result = concatenate(a, b);
   
   cout << a << b << endl;
   cout << result << endl;

   return 0;
}
