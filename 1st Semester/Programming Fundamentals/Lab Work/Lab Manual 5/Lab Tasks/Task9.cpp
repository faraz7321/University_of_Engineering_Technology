#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int i, x, l, count = 0;
    char array[100];
    bool flag = 0;

    cout << "Enter the string: ";
    cin >> array;
    l = strlen(array);
    for (i = 0; i < l; i++)
    {
        if (array[i] == 46)
        {
            count++;
            flag = 1;
        }
        else if (array[i] <= 46 || array[i] >= 57)
        {
            flag = 0;
            break;
        }
    }
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