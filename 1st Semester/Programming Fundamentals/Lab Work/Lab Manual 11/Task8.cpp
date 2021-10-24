#include <iostream>
#include <cstring>
#define BUFFER 1024
using namespace std;
int main()
{
    system("cls");
    short int i;
    char array[BUFFER];
    bool flag = 0;
    char *ptr = new char[BUFFER], l;
    cout << "Enter the string: ";
    cin >> ptr;
    l = strlen(ptr);

    for (i = 0; i < l; i++)
    {
        if (*(ptr + i) >= 48 && *(ptr + i) <= 57)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break; //If any alphabet is detected.//
        }
    }
    delete[] ptr;
    if (flag == 1)
    {
        cout << "User enter integer";
    }
    else if (flag == 0)
    {
        cout << "User enter string";
    }
    return 0;
}