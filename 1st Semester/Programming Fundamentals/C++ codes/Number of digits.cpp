#include<iostream>
using namespace std;
int main()

{
	//Lab Manual 3. Number of digits.
	int n,count=0,x;
	
	cout << "Enter integer: ";
	cin >> n;
	
	while(n!=0){ //While loop starts here//
		
		x=n%10;
		n=n/10;
		
		count=count+1;
	}//while loop ends here.
	
	cout << "Number of digits are: "<< count;
return 0;
}
