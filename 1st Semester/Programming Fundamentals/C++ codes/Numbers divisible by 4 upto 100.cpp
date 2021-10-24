#include<iostream>
using namespace std;
int main()

{
	// Lab manual 2, Task 4.
	// Numbers upto 100 which are divisible by 4
	int x;
	
	cout << "Numbers between 0 and 100 which are divisible by 4:" << endl;
	for (x=1; x<=100; x++){
		if (x%4==0){
			cout << x << ", ";
		}
	}
	
	
}
