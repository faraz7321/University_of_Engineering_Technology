#include <iostream>
#include <cstring>
using namespace std;
int return_bracket_value(char input[], int length);
bool brackets_flag(string str);
int main()
{
	system("CLS");
	char str[50];
	cout << "Input : ";
	cin >> str;
	bool flag = true;
	if (brackets_flag(str))
	{
		int length = strlen(str);
		int sum = 0;
		for (int i = 0; i < length; i++)
		{
			sum = sum + return_bracket_value(str, length);
			if (sum >= 0)
			{
			}
			else
			{
				flag = false;
				break;
			}
		}
	}
	else
	{
		flag = false;
	}
	if (flag==true)
	{
		cout << "True\n" << endl;
	}
	else
	{
		cout << "False\n" << endl;
	}
	return 0;
}
int return_bracket_value(char input[], int length)
{
	int value, j;
	for (int i = j; i < length; i++)
	{
		switch (input[i])
		{
		case '(':
			value = 1;
			break;
		case ')':
			value = -1;
			break;
		case '[':
			value = 3;
			break;
		case ']':
			value = -3;
			break;
		case '{':
			value = 5;
			break;
		case '}':
			value = -5;
			break;
		default:
			value = 0;
			break;
		}
	}
	j++;
	return value;
}
bool brackets_flag(string input)
{
	bool flag = false;
	int count[6]={0,0,0,0,0,0};
	for (int i = 0; i < input.size(); i++)
	{
		switch (input[i])
		{
		case '(':
		{
			count[0]++;
			break;
		}
		case ')':
		{
			count[1]++;
			break;
		}
		case '[':
		{
			count[2]++;
			break;
		}
		case ']':
		{
			count[3]++;
			break;
		}
		case '{':
		{
			count[4]++;
			break;
		}
		case '}':
		{
			count[5]++;
			break;
		}
		default:
			break;
		}
	}
	if ((count[0] == count[1]) && (count[2] == count[3]) && (count[4] == count[5]))
	{
		flag = true;
	}
	else
	{
		flag=false;
	}
	return flag;
}
