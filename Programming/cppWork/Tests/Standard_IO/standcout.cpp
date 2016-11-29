#include <iostream>

int main(void)  {
   std::cout << 0x42 << "\n";
   std::cout << 42 << "\n";
   std::cout << "42" << "\n";
   std::cout << 042 << std::endl; 
   // endl, "endline", creates a newline and
   // flushes the buffer, or writes whatever
   // was in the stream onto the device.
   // Be aware, this has some overhead.

   return 0;
}
