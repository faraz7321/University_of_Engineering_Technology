#include <iostream>
#include <string>
#define BUFFER 1024
using namespace std;
int main()
{
	int arr[BUFFER];
	int count = 1;
	int input;
	do
	{
		cout << "Input: ";
		cin >> input;
		for (int i = count; i >= 0; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = input;
		cout << "Output: {";
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << ",";
		}
		cout << "}" << endl;
		count++;
	} while (count != BUFFER);
	return 0;
}