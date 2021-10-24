#include <iostream>
using namespace std;
int main()
{
	system("cls");
	int n;
	short int i;
	cout << "Enter array size: ";
	cin >> n;
	int *ptr = new int[n];
	bool checkinc = false, checkdec = false;
	cout << "Enter Array Elements: ";
	for (i = 0; i < n; i++)
	{
		cin >> ptr[i];
	}
	for (i = 0; i < n - 1; i++)
	{
		if (*(ptr + i + 1) - *(ptr + i) > 0)
		{
			checkinc = true;
		}
		else if (*(ptr + i + 1) - *(ptr + i) < 0)
		{
			checkdec = true;
		}
	}
	delete[] ptr;
	if (checkdec == false && checkinc == true)
	{
		cout << "Array is increasing";
	}
	else if (checkdec == true && checkinc == false)
	{
		cout << "Array is decreasing";
	}
	else if (checkdec == false && checkinc == false)
	{
		cout << "Array is constant";
	}
	else if (checkdec == true && checkinc == true)
	{
		cout << "Array is increasing and decreasing";
	}
	return 0;
}