#include <iostream>
#include <cstring>
#define BUFFER 1024
using namespace std;
int main()
{
    system("cls");
    int i, x, l, count = 0;
    char *ptr = new char[BUFFER];
    bool flag = 0;
    cout << "Enter the string: ";
    cin >> ptr;
    l = strlen(ptr);
    for (i = 0; i < l; i++)
    {
        if (*(ptr + i) == 46)
        {
            count++;
            flag = 1;
        }
        else if (*(ptr + i) <= 46 || *(ptr + i) >= 57)
        {
            flag = 0;
            break;
        }
    }
    delete[] ptr;
    if (count != 1)
    {
        cout << "User entered value is not double";
        return 0;
    }
    if (flag == 1)
    {
        cout << "User entered value is double";
    }
    else if (flag == 0)
    {
        cout << "User entered value is not double";
    }
    return 0;
}