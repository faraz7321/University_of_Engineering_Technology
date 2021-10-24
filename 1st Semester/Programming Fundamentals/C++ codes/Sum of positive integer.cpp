#include<iostream>
using namespace std;
int main()

{
	////Lab manual 3. sum of numbers upto n
    int n=1;
    int x;
	int sum=0;
	
	cout << "Enter positive integer number: ";
	cin >> x;
	
   while( n<=x){ //while loop starts here.
   
      sum=sum+n;
      n=n+1;
   }//while loop ends here.
		cout << sum;
		
return 0;
}


