#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	system("cls");
	int length;
	short int i, j,count1 = 0, count2 = 0, count3 = 0;
	char *ptr = new char[40];
	cout << "Enter email Address: ";
	cin >> ptr;
	cout << endl;
	length = strlen(ptr);
	for (i = 0; i < length; i++)
	{
		if (*(ptr + i) == '@')
		{
			count1 = count1 + 1;
			for (j = i + 1; j < length; j++)
			{
				count2 = count2 + 1;
			}
		}
		else
		{
			count3 = count3 + 1;
		}
	}
	if (count1 == 1 && count2 > 4 && count3 > 0)
	{
		if (*(ptr + i - 4) == '.' && (*(ptr + i - 3) == 'c' || *(ptr + i - 3) == 'C') && (*(ptr + i - 2) == 'o' || *(ptr + i - 2) == 'O') && (*(ptr + i - 1) == 'm' || *(ptr + i - 1) == 'M'))
		{
			cout << "Valid Email address";
		}
		else
		{
			cout << "Invalid Email address!";
			return 0;
		}
	}
	else
	{
		cout << "Invalid Email address!";
	}
	return 0;
}