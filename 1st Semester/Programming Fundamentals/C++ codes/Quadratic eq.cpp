#include <iostream>
#include <cmath>
using namespace std;
int main ()

{
	// Lab manual 2, Task 3.
	//Solving Quadratic equations.
	
	float a, b, c, d, x1, x2 , x3;

	
	cout << "To calculate root of a quadratic equation, enter value of: " << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	cout << "c= ";
	cin >> c;
	
    d = b*b - 4*a*c;
	if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Root 1: " << x1 << endl;
        cout << "Root 2: " << x2 << endl;
	}
	else if (d==0){
		x3 = (-b  / ( 2 * a));
		cout << x3 << endl;
	}
	else (cout << "Imaginary Roots");
	
return 0;
}
