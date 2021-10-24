#include<iostream>
#include<cmath>
using namespace std;
int main()

{
	// Lab manual 3, Task 3.
	//Solving Quadratic equations.
	
	float a, b, c, d, x1, x2 , x3;

	cout << "Enter coefficients of A: ";
	cin >> a;
	cout << "Enter coefficients of B: ";
	cin >> b;
	cout << "Enter coefficients of C: ";
	cin >> c;
	
    d = b*b - 4*a*c;
	if (d > 0) {
		cout << "Roots are real and distinct.";
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Root 1: " << x1 << endl;
        cout << "Root 2: " << x2 << endl;
	}
	else if (d==0){
		cout << "Roots are real and equal.";
		x3 = (-b  / ( 2 * a));
		cout << x3 << endl;
	}
	else (cout << "Roots are complex and different");
	
return 0;
}
