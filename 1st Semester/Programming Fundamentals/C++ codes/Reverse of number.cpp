#include <iostream>

using namespace std;
int main()
{
   //eg. 142 to 241*2
   int x;
   int n;
   int c=0;
   
   cout << "Enter number: ";
   cin >> n;
   if (n>0)
   {
      while (!(n==0))
      {
         x =n % 10;
         n =n/10;
         
cout << x <<endl;
		 
		}
   }
   else{
   }

 return 0;
}
