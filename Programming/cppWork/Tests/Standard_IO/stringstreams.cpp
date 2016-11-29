// stringstreams
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()  {
   string mystr;
   float price=0;
   int quantity; 
   
   cout << "Enter price: ";
   getline(cin, mystr);
   stringstream(mystr) >> price;
   cout << "Enter a quantity: ";
   getline(cin, mystr); 
   stringstream(mystr) >> quantity;
   cout << "Total price: " << price*quantity << endl;
   return 0;
}
