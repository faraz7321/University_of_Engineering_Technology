#include<iostream>
using namespace std;
int main()

{
	// Lab manual 2, Task 6
	//Calculate the sum of numbers between two limits
    int n;
    int y;
	int sum=0;
	

	cin >> y;
	cout << "Sum of numbers between "<< y;
	

   for( n=1; n<=y; n++)
   {
      sum=sum+n;
   }
		cout << sum;
		

	}
	
	

