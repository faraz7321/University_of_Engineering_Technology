#include <iostream>
using namespace std;
int main()
{
   //Lab manual 3. gcd
   int x, a;
   int y, b;
   int z;
   
   cout << "Enter first number: ";
   cin >> x;

   cout << "Enter second number: ";
   cin >> y;
   a=x; //Values stored to calculate LCM.//
   b=y;
   while (y!=0){//while loop starts here.
      z =y;
      y =x % y;
      x =z;
   }//while loop ends here.   

//x= GCD. LCM = x*y (input by user), divided by GCD.//
   cout << "LCM is: "<< a*b/x << endl;
   return 0;
}
