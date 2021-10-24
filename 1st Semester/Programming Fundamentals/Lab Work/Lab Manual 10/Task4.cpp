#include <iostream>
using namespace std;

int main()
{
	int n, fact;
	int x;
	cout << "Enter the size of array: ";
	cin >> n;
	int array[n];
	cout << "Enter the array elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	cout << "Rotation Factor: ";
	cin >> fact;
	cout << "Array elements after rotation: ";
	for (int i = 0; i < n; i++)
	{
		x = (i + fact) % n;
		cout << array[x] << " ";
	}
	return 0;
}