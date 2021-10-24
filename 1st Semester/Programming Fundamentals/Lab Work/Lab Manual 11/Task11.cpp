#include <iostream>
using namespace std;
int main()
{
	system("cls");
	int n;
	short int i;
	cout << "Enter the size of array: ";
	cin >> n;
	int *ptr = new int[n];
	cout << "Enter Array Elements: ";
	for (i = 0; i < n; i++)
	{
		cin >> *(ptr + i);
	}
	cout << "Sorted array: ";
	for (i = 0; i < n; i++)
	{
		if (*(ptr + i) >= 0)
		{
			cout << *(ptr + i) << " ";
		}
	}
	//Negative numbers.//
	for (i = 0; i < n; i++)
	{
		if (*(ptr + i) < 0)
		{
			cout << *(ptr + i) << " ";
		}
	}
	delete[] ptr;
	return 0;
}
