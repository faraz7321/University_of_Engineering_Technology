#include <iostream>
using namespace std;
int main()
{
    int n, i, j = 1;
    cout << "Enter the size of array: ";
    cin >> n;

    int array[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter array element " << j << ": ";
        cin >> array[i];
        j++;
    }
    cout << "Output array is " << endl << array[0] * array[1] << " ";
    for (i = 1; i < n - 1; i++)
    {
        cout << array[i + 1] * array[i - 1] << " ";
    }
    cout << array[n-1] * array[n - 2];
    return 0;
}