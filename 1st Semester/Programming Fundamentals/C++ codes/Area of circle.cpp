#include <iostream>
#include <cmath>
using namespace std;
int main ()

{
	// Lab manual 2, Task 2.
	//Calculating area of a circle.
	float x;
	float A;
	
	cout << "Enter a radius of a circle to calculate its area " << endl;
	cin  >> x;
	A = (x*x)*3.14159;
	cout << "Area= " << A;
	 
return 0;
}
