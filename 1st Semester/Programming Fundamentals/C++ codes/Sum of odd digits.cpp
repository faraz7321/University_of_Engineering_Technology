#include <iostream>
using namespace std;
int main()

{
   
   int x;
   int n;
   int sum=0;
   
   cout << "Enter number: ";
   cin >> n;
   if (n>0){
      while (!(n==0)){
         x =n % 10;
         n =n/10;
         //cout<< x;
         if (x%2!=0){
         	sum=sum+x;
         	
		 }
		}
		
   }
   
            	cout << sum;
  

 return 0;
}
