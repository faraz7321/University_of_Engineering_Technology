#include <iostream>
using namespace std;
int main()
{
    int n, i, j = 1, s = 0, l = 0;
    cout << "Enter the size of array: ";
    cin >> n;

    int array[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter array elements " << j << ": ";
        cin >> array[i];
        j++;
    }
    s = array[3]; 

        for (i = 0; i < n; i++)
    {
        if (l < array[i])
        {
            l = array[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (s > array[i])
        {
            s = array[i];
        }
    }
    cout << "Smallest Element: " << s << endl
         << "Largest Element: " << l;
    return 0;
}