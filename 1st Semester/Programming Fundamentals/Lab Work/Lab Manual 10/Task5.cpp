#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string input;

	cout << "Input: ";
	getline(cin, input);
	int len=input.size();
	cout << "Output: \"";
	for (int i = len; i >= 0; i--)
	{
		cout << input[i];
	}
	cout << "\"";
	return 0;
}
