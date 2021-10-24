#include <iostream>
using namespace std;
int main()
{
	int n;
	cout <<"Enter array size: ";
	cin >> n;
	int array[n];
	bool checkinc = false, checkdec = false;
	cout << "Enter Array Elements:";
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	for (int i = 0; i < 8; i++)
	{
		if ((array[i + 1] - array[i]) > 0)
		{
			checkinc = true;
		}
		else if ((array[i + 1] - array[i]) < 0)
		{
			checkdec = true;
		}
	}
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