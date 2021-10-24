#include <iostream>
using namespace std;
int main()
{
    system("cls");
    short int i, j = 1, k;
    int n, x;
    cout << "Enter the size of array: ";
    cin >> n;
    int *ptr = new int[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter array element " << j << ": ";
        cin >> ptr[i];
        j++;
    }
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (*(ptr + i) > *(ptr + k))
            {
                x = *(ptr + i);
                *(ptr + i) = *(ptr + k);
                *(ptr + k) = x;
            }
        }
    }
    cout << "Sorted array is\n";
    for (i = 0; i < n; i++)
    {
        cout << *(ptr + i) << " ";
    }
    delete[] ptr;
    return 0;
}