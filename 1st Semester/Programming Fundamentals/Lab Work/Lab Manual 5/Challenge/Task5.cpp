#include <iostream>
using namespace std;
int main()
{
	int n, i, s = 0, l = 0, j, s1=0;
	cout << "Enter the size of array: ";
	cin >> n;

	int array[n];
	cout << "Enter Array Elements: ";
	for (i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	//To get largest number in the array.//
	for (i = 0; i < n; i++)
	{
		if (l <= array[i])
		{
			l = array[i];
		}
	}
	//To get the smallest number in the array.//
	s=array[2];
	for (i = 0; i < n; i++)
	{
		if (s > array[i])
		{
			s = array[i];
			j=i;
		}
	}
	//To check second smallest number from 0 to j(s).//
	s1=array[2];
	for (i = 0; i < j; i++)
	{
		if (s1 > array[i])
		{
			s1 = array[i];
		}
	}
	//To check second smallest number from j(s) to n.//
	for (i = j+1; i < n; i++)
	{
		if (s1 > array[i])
		{
			s1 = array[i];
		}
	}

	cout << "Maximum Difference: " << l-s << endl
		 << "Minimum Difference: " << s1-s;
	return 0;
}