#include <iostream>
using namespace std;
int main()
{
    system("cls");
    //Input of elements.//
    int i, x, k;
    int n;
    cout << "Enter even size of array: ";
    cin >> n;
    int *ptr = new int[n];
    cout << "Enter array elements "
         << ": ";
    for (i = 0; i < n; i++)
    {
        cin >> *(ptr + i);
    }
    //Sorting array in acending order.//
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
    cout << "Seperated array is: ";
    //Output for even array.//
    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) % 2 == 0)
            cout << *(ptr + i) << " ";
    }
    //Output for odd array.//
    for (i = 0; i < n; i++)
    {
        if (*(ptr + i) % 2 != 0)
            cout << *(ptr + i) << " ";
    }
    delete[] ptr;
    return 0;
}