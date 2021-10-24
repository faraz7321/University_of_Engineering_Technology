#include<iostream>
using namespace std;
int main()

{
	//Lab manual 3. Right angle triangle
	int a, b, c;
	
	cout << "Enter Side-1 lenght of triangle: ";
	cin >> a;
	
	cout << "Enter Side-2 lenght of triangle: ";
	cin >> b;
	
	cout << "Enter Side-3 lenght of triangle: ";
	cin >> c;
	
	if (a>b && a>c && a*a==b*b+c*c || b>a && b>c && b*b==a*a+c*c || c>a && c>b && c*c==b*b+a*a){
		cout << "Given triangle is a right-angle triangle.";
	}

	else {
	
		cout << "Given triangle is not a right-angle triangle.";
		
}
return 0;
}
