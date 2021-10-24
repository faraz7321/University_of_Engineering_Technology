#include <iostream>
#include<cmath>
using namespace std;
int main()

{
   int x=0, in, a, p=0, dec=0;
 
   cout << "Enter a binary number: ";
   cin >> in;
   a=in;
   while (in!=0){
      x=in%10; in=in/10;
      dec=dec+x*pow(2,p);
      p=p+1;
   }
   cout << "Binary number " << a << " = " << dec << " in decimal number." << endl;
   return 0;
}
