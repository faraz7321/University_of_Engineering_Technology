#include <iostream>
using namespace std;
int main()
{
    system("cls");
    int s = 0, l = 0, n;
    short int i, j = 1;
    cout << "Enter the size of array: ";
    cin >> n;
    int *ptr = new int[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter array elements " << j << ": ";
        cin >> ptr[i];
        j++;
    }
    s = *ptr + 3;

    for (i = 0; i < n; i++) //For largest number
    {
        if (l < *(ptr + i))
        {
            l = *(ptr + i);
        }
    }
    for (i = 0; i < n; i++) //For Smallest number
    {
        if (s > *(ptr + i))
        {
            s = *(ptr + i);
        }
    }
    delete[] ptr;
    cout << "Smallest Element: " << s << endl
         << "Largest Element: " << l;
    return 0;
}