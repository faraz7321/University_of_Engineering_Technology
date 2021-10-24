#include<iostream>
using namespace std;
int main()

{
	// Lab manual 2, Task 4.
	// Numbers upto N which are divisible by 4
	int n;
	int x;
	
	cout << "Numbers between 0 and N which are divisible by 4:" << endl;
	cin >> n;
	for (x=4; x<=n; x++){
		if (x%4==0){
			cout << x <<", ";
		}
	}
	
	
}
