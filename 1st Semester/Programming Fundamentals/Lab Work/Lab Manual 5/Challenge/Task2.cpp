#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()

{
	int array[5], sum[5], sqr[5], cube[5], i, gt = 0;
	cout << "Enter Array Elements: ";

	for (i = 0; i < 5; i++)
	{
		cin >> array[i];
		//Assinments.//
		sqr[i] = pow(array[i], 2);
		cube[i] = pow(array[i], 3);
		sum[i] = array[i] + cube[i] + sqr[i];
	}
	cout << endl;

	cout << left << setw(10) << "Numbers: ";
	//Numbers.//
	for (i = 0; i < 5; i++)
	{
		cout << left << setw(5) << array[i];
	}
	cout << endl;
	//Squares.//
	cout << left << setw(10) << "Squares: ";
	for (i = 0; i < 5; i++)
	{
		cout << left << setw(5) << sqr[i];
	}
	cout << endl;
	//Cube.//
	cout << left << setw(10) << "Cubes: ";
	for (i = 0; i < 5; i++)
	{
		cout << left << setw(5) << cube[i];
	}
	cout << endl;
	//Sum.//
	cout << left << setw(10) << "Sums: ";
	for (i = 0; i < 5; i++)
	{
		cout << left << setw(5) << sum[i];
	}
	cout << endl;
	//Grand Total.//
	for (i = 0; i < 5; i++)
	{
		gt = gt + sum[i];
	}

	cout << "Grand total: " << gt;
	return 0;
}