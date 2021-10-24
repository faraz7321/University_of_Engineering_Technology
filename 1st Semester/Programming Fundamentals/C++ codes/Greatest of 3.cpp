#include <iostream>
using namespace std;
int main()
{
  
   int x;
   int y;
   int z;

   ;
   cout << "Enter first number" << endl;
   cin >> x;

   cout << "Enter second number" << endl;
   cin >> y;

   cout << "Enter third number" << endl;
   cin >> z;
   if (x>y && x>z){
      cout << "Largest number: " << x << endl;   
      }
   else if (y>x && y>z){
         cout << "Largest number: " << y << endl;      
         }
      else if (z>x && z>y){
            cout <<"Largest number: " << z << endl;         
            }
   

   return 0;
}
