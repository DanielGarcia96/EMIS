#include <iostream>
#include <string>
#include <sstream>

struct Map {
   int x;
   int y;
   char heading;
};

int main(void)  {
   struct Map m = { 2, 1, 'N' };
   std::cout << "Coordinates: " << m.x << ", " << m.y << "\n";
   std::cout << "Heading: " << m.heading << "\n";
   return 0;
}
