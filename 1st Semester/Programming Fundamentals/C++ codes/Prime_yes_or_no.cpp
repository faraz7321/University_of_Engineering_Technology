#include <iostream>
using namespace std;
int main()

{

   int a; //Dummy var just to hold the conditions
   int n;
   int b;

   cout << "Enter number to check if its prime or not: ";
   cin >> n;
   cout << endl;

   if (n > 2)
   { //If this (n>2) condition remains true, while loop will run.
      a = 1;
      b = 0;
      //Dummy var just to hold the conditions.
      while (!(a >= n))
      {
         if (n % a == 0)
         {
            b = b + 1;
         }

         else
         {
         }
         a = a + 1;
      } //While loop ends here.

      if (b == 1)
      {
         cout << n << " is a prime number." << endl;
      }
      else
      {
         cout << n << " is not a prime number." << endl;
      }
   } //If statement ends here.

   else
   { // In case of n<=2^^^
      cout << n << " is not a prime number." << endl;
   }

   return 0;
}
