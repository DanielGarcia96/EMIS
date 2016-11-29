#include <iostream>
using namespace std;

enum class Colors {black, blue, green, cyan, red, purple, yellow, white};

int main()  {
   Colors mycolor;
   mycolor = Colors::red;

   if (mycolor == Colors::blue)
      cout << "blue" << endl;
   else if (mycolor == Colors::green)
      cout << "green" << endl;
   else
      cout << "other" << endl;

   return 0;
}
