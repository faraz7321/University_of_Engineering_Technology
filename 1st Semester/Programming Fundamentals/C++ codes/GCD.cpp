#include <iostream>
using namespace std;
int main()
{
   //Lab manual 3. GCD.
   int b;
   int c;
   int a;

   cout << "Enter first number: ";
   cin >> a;

   cout << "Enter second number: ";
   cin >> b;
   while (b!=0){//while loop starts here.
      c =b;
      b =a % b;
      a =c;
   }//while loop ends here.
   cout << "GCD is: "<< a << endl;
   return 0;
}
