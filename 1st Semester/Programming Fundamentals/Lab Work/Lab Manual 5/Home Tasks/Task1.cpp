#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()

{
	int array[10], i;

	cout << "Enter Array Elements: ";
	for (i = 0; i < 10; i++)
	{
		cin >> array[i];
	}
	//cout << "Sorted array: ";
	//Positive numbers.//
	for (i = 0; i < 10; i++)
	{
		if (array[i] >= 0)
		{
			cout << array[i] << " ";
		}
	}
	//Negative numbers.//
	for (i = 0; i < 10; i++)
	{
		if (array[i] < 0)
		{
			cout << array[i] << " ";
		}
	}
	return 0;
}
