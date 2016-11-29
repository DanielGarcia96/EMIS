#include <iostream>
using namespace std;

struct book1_t   {
   char title[50];
   char author[50];
   union  {
     float dollars;
     int yen;
   } price;
} book1;

struct book2_t   {
   char title[50];
   char author[50];
   union  {
     float dollars;
     int yen;
   };
} book2;

int main()  {
   struct book1_t b1 = { "The Shining", "Stephen King", 5.00 };
   struct book2_t b2 = { "Leaves of Grass", "Walt Whitman", 0 };
   //need to set the anonymous union to 0 to clear out the
   //garbage before you can use it.
   b2.yen = 100;

   cout << b1.title << " " << b1.author << " " << b1.price.dollars << endl;
   cout << b2.title << " " << b2.author << " " << b2.yen << endl;
   return 0;
}
