#include <iostream>
#include <cmath>
using namespace std;
int main ()

{
	// Lab manual 2, Task 1.
	// Check whether a number N is divisible by 3
	int x;
	
	cout << "Enter any number to check wether it is divisible by 3 or not" << endl;
	cin >> x;
	
	if(x % 3 == 0){
		cout << x << " is divisible by 3.";
	}
	else {
		cout << x << " is not divisible by 3.";
	}
return 0;
}
