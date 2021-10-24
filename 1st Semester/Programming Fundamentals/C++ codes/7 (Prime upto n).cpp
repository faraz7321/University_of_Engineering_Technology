#include<iostream>
using namespace std;
int main()

{
	//Lab manual 3. Prime numbers upto n.//   //i=n  num=x
	int n=2, x, count, in;
	
	cout << "Enter number for prime number list: ";
	cin >> in;
	cout << "Prime numbers are: ";

	   while (n<=in){ //Increment in n upto Input number.//
           count=0;

		   x=n; //to check Prime.
		   
          while(x>=1){

             if(n%x==0){
 		count=count+1;
	     }
		   x=x-1;
	  }
	  if (count==2){
	  	cout << n << ", ";
	  }
	   n=n+1;
}
   return 0;
}
