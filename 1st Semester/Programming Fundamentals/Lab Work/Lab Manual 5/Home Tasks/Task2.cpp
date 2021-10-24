#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()

{
	int n, input,i;
	cout << "Enter the size of array: ";
	cin >> n;
	int array[n];

	cout << "Enter Array Elements: ";
	for (i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	cout << "Enter Element to Search: ";
	cin >> input;
	for (i = 0; i < n; i++)
	{
		if (input == array[i])
		{
			cout << input << " exist in given array" << endl
				 << "Location of searched number is " << i
				 << " index of array" << endl;
		}
	}

	return 0;
}
