#include <iostream>
using namespace std;
int main()
{
    system("cls");
    int n;
    short int i, j = 1, k, count;
    cout << "Enter the size of array: ";
    cin >> n;
    int *ptr = new int[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter array elements " << j << ": ";
        cin >> ptr[i];
        j++;
    }
    cout << "Elements of array that appear once in an array: ";
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (k = 0; k < n; k++)
        {
            if (*(ptr + k) == *(ptr + i))
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << *(ptr + i) << " ";
        }
    }
    delete[] ptr;
    return 0;
}