// basic file operations
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])  {
   std::ofstream myfile;
   myfile.open("example.txt");
   myfile << "Writing this to a file.\n";
   std::cout << myfile.good() << "\n";
   myfile.close();
   return 0;
}
