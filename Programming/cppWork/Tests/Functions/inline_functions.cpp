#include <iostream>
#include <string>
using namespace std;

inline string concatenate(const string& a, const string& b)  {
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
