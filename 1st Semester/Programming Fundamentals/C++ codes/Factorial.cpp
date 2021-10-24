#include<iostream>
using namespace std;
int main()

{
	//Lab Manual 2, Task 8.
	// Calculating Factorial.
	int a, f, n;
	f=1;
	
	cout << "Enter Any Number to Calculate its Factorial: ";
	cin >> n;
	for (a=1; a<=n; a++){
		f=f*a;
	}
	
	cout << "Factorial of " << n << " is= "<< f << endl;  
	
return 0;
}
