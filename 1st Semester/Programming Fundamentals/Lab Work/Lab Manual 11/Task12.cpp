#include <iostream>
using namespace std;
int main()
{
	system("cls");
	int n, input;
	short int i;
	cout << "Enter the size of array: ";
	cin >> n;
	int *ptr = new int[n];
	cout << "Enter Array Elements: ";
	for (i = 0; i < n; i++)
	{
		cin >> ptr[i];
	}
	cout << "Enter Element to Search: ";
	cin >> input;
	for (i = 0; i < n; i++)
	{
		if (input == *(ptr + i))
		{
			cout << input << " exist in given array" << endl
				 << "Location of searched number is " << i
				 << " index of array" << endl;
		}
	}
	delete[] ptr;
	return 0;
}
