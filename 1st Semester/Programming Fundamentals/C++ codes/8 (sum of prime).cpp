#include<iostream>
using namespace std;
int main()

{
	//Lab manual 3. Prime numbers upto n.//   //i=n  num=x
	int n=2, x, count, in, sum=0;
	
	cout << "Enter number: ";
	cin >> in;
	cout << "Sum of prime numbers is: ";
	
	
	//loop for prime numbers.
	
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
	  	sum=sum+n; //stores n into sum.
	  }
	   n=n+1;  
} //While loop of prime numbers end.

cout << sum;

   return 0;
}
	
	
	   
